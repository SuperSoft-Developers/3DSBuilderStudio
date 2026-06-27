#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QString>

class ProjectManager
{
public:
    ProjectManager();

    bool createProject(const QString &projectName,
                       const QString &directory);

    bool openProject(const QString &projectFile);

    bool saveProject();

    QString projectName() const;
    QString projectPath() const;

private:
    QString m_projectName;
    QString m_projectPath;
};

#endif
