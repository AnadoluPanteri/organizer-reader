
/**
 * MeeGo 1.2 Harmattan CLI Organizer Reader
 * Copyright (c) 2012-06-04 Thomas Perl <m@thp.io>
 * Released under the terms of the GNU GPLv3 or later.
 **/

#include <QtGui>

#include <QOrganizerManager>
#include <QOrganizerItem>
#include <QOrganizerEventTime>

QTM_USE_NAMESPACE


QString getEvents(int days=3) {
    QString result = "";

    QOrganizerManager manager;

    QDateTime now = QDateTime::currentDateTime();
    QDateTime then = now.addDays(days);
    QList<QOrganizerItem> items = manager.items(now, then);

    QOrganizerItem item;
    foreach (item, items) {
        if (item.type() == "Event") {
            QDateTime start = item.detail<QOrganizerEventTime>()
                .startDateTime();

            if (start.date() != now.date()) {
                result += start.toString("d. MMM");
                result += " ";
            }

            result += start.toString("HH:mm");
            result += ": ";
            result += item.displayLabel();
            result += '\n';
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextStream out(stdout);
    out << getEvents();

    return 0;
}

