#ifndef __MainApp_H__
#define __MainApp_H__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MainApp: public wxApp
{
public:
    virtual bool OnInit();
};

#endif