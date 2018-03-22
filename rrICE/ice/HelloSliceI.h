#ifndef __HelloSliceI_h__
#define __HelloSliceI_h__

#include <HelloSlice.h>
//base

namespace HelloSlice
{

class HelloServiceItfI : public virtual HelloServiceItf
{
public:

    virtual void sayHello(::std::string,
                          const Ice::Current&) override;
};

}

#endif
