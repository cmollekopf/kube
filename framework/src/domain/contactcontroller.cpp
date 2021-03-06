/*
 *  Copyright (C) 2017 Michael Bohlender, <michael.bohlender@kdemail.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "contactcontroller.h"

#include <sink/applicationdomaintype.h>
#include <KContacts/VCardConverter>

class MailsController : public Kube::ListPropertyController
{
public:

    MailsController()
        : Kube::ListPropertyController{{"email"}}
    {
    }

};

class PhonesController : public Kube::ListPropertyController
{
public:

    PhonesController()
        : Kube::ListPropertyController{{"number"}}
    {
    }

};

ContactController::ContactController()
    : Kube::Controller(),
    controller_mails{new MailsController},
    controller_phones(new PhonesController),
    action_save{new Kube::ControllerAction{this, &ContactController::save}}
{
    updateSaveAction();
}

void ContactController::save() {
    qWarning() << "Saving is not implemented";
}

void ContactController::updateSaveAction()
{
    saveAction()->setEnabled(!getName().isEmpty());
}

void ContactController::loadContact(const QVariant &contact)
{
    if (auto c = contact.value<Sink::ApplicationDomain::Contact::Ptr>()) {
        setName(c->getFn());
        const auto &vcard = c->getVcard();
        KContacts::VCardConverter converter;
        const auto addressee = converter.parseVCard(vcard);
        setEmails(addressee.emails());
        QStringList numbers;
        for (const auto &n : addressee.phoneNumbers()) {
            numbers << n.number();
        }
        setPhoneNumbers(numbers);

        for(const auto &a :addressee.addresses()) {
            setStreet(a.street());
            setCity(a.locality());
            setCountry(a.country());
            break;
        }
        setCompany(addressee.organization());
        setJobTitle(addressee.role());
        setImageData(addressee.photo().rawData());
    }
}

QVariant ContactController::contact() const
{
    return QVariant{};
}

void ContactController::removeEmail(const QString &email)
{
    auto emails = getEmails();
    emails.removeAll(email);
    setEmails(emails);
}

void ContactController::addEmail(const QString &email)
{
    auto emails = getEmails();
    emails.append(email);
    setEmails(emails);
}
