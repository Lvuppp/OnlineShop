#ifndef REQUEST_H
#define REQUEST_H


class Request
{
public:
    Request();
    virtual ~Request();
    virtual void getRequest() = 0;
};

#endif // REQUEST_H
