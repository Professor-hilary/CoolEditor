/***************************************************************
 * Name:      CoolEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    prof hilary (profesorhilary@outlook.com)
 * Created:   2024-07-14
 * Copyright: prof hilary ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "CoolEditorApp.h"

//(*AppHeaders
#include "CoolEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CoolEditorApp);

bool CoolEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CoolEditorFrame* Frame = new CoolEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
