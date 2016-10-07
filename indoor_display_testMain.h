/***************************************************************
 * Name:      indoor_display_testMain.h
 * Purpose:   Defines Application Frame
 * Author:    Novica Peric (novica.peric@d-logic.rs)
 * Created:   2016-09-23
 * Copyright: Novica Peric (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef INDOOR_DISPLAY_TESTMAIN_H
#define INDOOR_DISPLAY_TESTMAIN_H

//(*Headers(indoor_display_testFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/clrpicker.h>
#include <wx/statusbr.h>
//*)

class indoor_display_testFrame: public wxFrame
{
    public:

        indoor_display_testFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~indoor_display_testFrame();

    private:

        //(*Handlers(indoor_display_testFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBtnOpenClick(wxCommandEvent& event);
        void OnBtnBmpClick(wxCommandEvent& event);
        void OnBtnSetColorClick(wxCommandEvent& event);
        void OnBtnGetColorClick(wxCommandEvent& event);
        void OnBtnBmpMonoClick(wxCommandEvent& event);
        void OnBtnSetConfClick(wxCommandEvent& event);
        void OnBtnCloseClick(wxCommandEvent& event);
        void OnBtnLoadFileClick(wxCommandEvent& event);
        void OnBtnLoadRgbFileClick(wxCommandEvent& event);
        void OnBtnFwVerClick(wxCommandEvent& event);
        void OnBtnDllVerClick(wxCommandEvent& event);
        void OnBtnGetConfClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(indoor_display_testFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON7;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON6;
        static const long ID_BUTTON11;
        static const long ID_BUTTON5;
        static const long ID_BUTTON2;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_BUTTON10;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(indoor_display_testFrame)
        wxButton* BtnClose;
        wxButton* BtnSetColor;
        wxColourPickerCtrl* ColourPickerCtrl;
        wxStaticText* LblBright;
        wxButton* BtnBmp;
        wxButton* BtnLoadFile;
        wxButton* BtnFwVer;
        wxFileDialog* OpenFile;
        wxButton* BtnDllVer;
        wxButton* BtnGetColor;
        wxButton* BtnSetConf;
        wxTextCtrl* TxtBright;
        wxStatusBar* StatusBar;
        wxButton* BtnBmpMono;
        wxButton* BtnGetConf;
        wxButton* BtnOpen;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // INDOOR_DISPLAY_TESTMAIN_H
