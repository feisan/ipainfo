#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wui.h"

class MainFrame : public _MainFrame
{
public:
    MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size);
    virtual ~MainFrame();
protected:
    virtual void OnOpenButtonClicked(wxCommandEvent& event);
private:
    void ProcessIPA(const wxString& ipaFilePath);
};
#endif // MAINFRAME_H
