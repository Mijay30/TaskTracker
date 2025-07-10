#include "task.h"

Task::Task(const QString &title, const QString &description, const QDate &dueDate, bool completed)
    : m_title(title), m_description(description), m_dueDate(dueDate), m_completed(completed) {}

QString Task::getTitle() const {
    return m_title;
}

QString Task::getDescription() const {
    return m_description;
}

QDate Task::getDueDate() const {
    return m_dueDate;
}

bool Task::isCompleted() const {
    return m_completed;
}
