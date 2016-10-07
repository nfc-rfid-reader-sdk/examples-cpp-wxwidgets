/***************************************************************
 * Name:      indoor_display_testApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Novica Peric (novica.peric@d-logic.rs)
 * Created:   2016-09-23
 * Copyright: Novica Peric (www.d-logic.net)
 * License:
 **************************************************************/

#include "indoor_display_testApp.h"

//(*AppHeaders
#include "indoor_display_testMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(indoor_display_testApp);

bool indoor_display_testApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	indoor_display_testFrame* Frame = new indoor_display_testFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
