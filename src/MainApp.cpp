#include "MainApp.h"
#include "MainFrame.h"


bool MainApp::OnInit()
{
    MainFrame *frame = new MainFrame( NULL, -1,  "IPA File Infomation", wxDefaultPosition, wxSize(640,480) );
    frame->Show( true );
    return true;
}
