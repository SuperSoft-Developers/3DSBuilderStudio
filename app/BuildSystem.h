#ifndef BUILDSYSTEM_H
#define BUILDSYSTEM_H

#include <QString>

class BuildSystem
{
public:
    BuildSystem();

    QString build();

private:
    bool runCommand(const QString &program,
                    const QStringList &arguments,
                    QString &output);
};

#endif
