#ifndef SQLREQUESTFACTORY_H
#define SQLREQUESTFACTORY_H

#include <QObject>

#include "request.h"

class SqlRequestFactory
{
public:
    SqlRequestFactory();
    virtual ~SqlRequestFactory();
    virtual Request *getRequestFromFactory(const QString&) = 0;
};

#endif // SQLREQUESTFACTORY_H
