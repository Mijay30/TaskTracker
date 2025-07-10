#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task {
public:
    Task(const QString &title, const QString &description, const QDate &dueDate, bool completed);

    QString getTitle() const;
    QString getDescription() const;
    QDate getDueDate() const;
    bool isCompleted() const;

private:
    QString m_title;
    QString m_description;
    QDate m_dueDate;
    bool m_completed;
};

#endif
