/***************************************************************
 * Name:      indoor_display_testMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Novica Peric (novica.peric@d-logic.rs)
 * Created:   2016-09-23
 * Copyright: Novica Peric (www.d-logic.net)
 * License:
 **************************************************************/

#include "indoor_display_testMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(indoor_display_testFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "lib/include/indoor_display_lib.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(indoor_display_testFrame)
const long indoor_display_testFrame::ID_BUTTON1 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON7 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON3 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON4 = wxNewId();
const long indoor_display_testFrame::ID_COLOURPICKERCTRL1 = wxNewId();
const long indoor_display_testFrame::ID_STATICTEXT1 = wxNewId();
const long indoor_display_testFrame::ID_TEXTCTRL1 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON6 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON11 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON5 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON2 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON8 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON9 = wxNewId();
const long indoor_display_testFrame::ID_BUTTON10 = wxNewId();
const long indoor_display_testFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(indoor_display_testFrame,wxFrame)
    //(*EventTable(indoor_display_testFrame)
    //*)
END_EVENT_TABLE()

indoor_display_testFrame::indoor_display_testFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(indoor_display_testFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer5;

    Create(parent, id, _("RGB INDOOR DISPLAY EXAMPLE ver 1.0"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, wxEmptyString);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Display connection"));
    BtnOpen = new wxButton(this, ID_BUTTON1, _("CONNECT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer2->Add(BtnOpen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnClose = new wxButton(this, ID_BUTTON7, _("DISCONNECT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    StaticBoxSizer2->Add(BtnClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Default color setting"));
    BtnSetColor = new wxButton(this, ID_BUTTON3, _("SET COLOR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer3->Add(BtnSetColor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnGetColor = new wxButton(this, ID_BUTTON4, _("GET COLOR"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer3->Add(BtnGetColor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(255,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    StaticBoxSizer3->Add(ColourPickerCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Display brightness setting"));
    LblBright = new wxStaticText(this, ID_STATICTEXT1, _("Brightness"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer4->Add(LblBright, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TxtBright = new wxTextCtrl(this, ID_TEXTCTRL1, _("10"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer4->Add(TxtBright, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnSetConf = new wxButton(this, ID_BUTTON6, _("SET CONFIG"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticBoxSizer4->Add(BtnSetConf, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnGetConf = new wxButton(this, ID_BUTTON11, _("GET CONFIG"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    StaticBoxSizer4->Add(BtnGetConf, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bitmap operation"));
    BtnBmpMono = new wxButton(this, ID_BUTTON5, _("MONO BMP LOAD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer5->Add(BtnBmpMono, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnBmp = new wxButton(this, ID_BUTTON2, _("RGB BMP LOAD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer5->Add(BtnBmp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("BMP file operation"));
    BtnLoadFile = new wxButton(this, ID_BUTTON8, _("LOAD BMP FILE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    StaticBoxSizer6->Add(BtnLoadFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Version"));
    BtnFwVer = new wxButton(this, ID_BUTTON9, _("DISPLAY VERSION"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    StaticBoxSizer7->Add(BtnFwVer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnDllVer = new wxButton(this, ID_BUTTON10, _("DLL VERSION"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    StaticBoxSizer7->Add(BtnDllVer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(StaticBoxSizer1);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    OpenFile = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    StaticBoxSizer1->Fit(this);
    StaticBoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnOpenClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnCloseClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnSetColorClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnGetColorClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnSetConfClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnGetConfClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnBmpMonoClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnBmpClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnLoadFileClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnFwVerClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&indoor_display_testFrame::OnBtnDllVerClick);
    //*)
}

indoor_display_testFrame::~indoor_display_testFrame()
{
    //(*Destroy(indoor_display_testFrame)
    //*)
}

void indoor_display_testFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void indoor_display_testFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void indoor_display_testFrame::OnBtnOpenClick(wxCommandEvent& event)
{
    unsigned long status;

    status = DisplayOpen();
    if(status)
        StatusBar->SetLabelText("Display did not connect");
    else
        StatusBar->SetLabelText("Display connected");
}

void indoor_display_testFrame::OnBtnBmpClick(wxCommandEvent& event)
{
   unsigned long status;
   unsigned char bmp_data[1024];
   unsigned short i;

   for(i = 0; i < 144; i++)
   {
       if(i < 48)
       {
            bmp_data[i * 3] = 0;
            bmp_data[i * 3 + 1] = 0;
            bmp_data[i * 3 + 2] = 255;
       }
       else if(i < 96)
       {
           bmp_data[i * 3] = 255;
           bmp_data[i * 3 + 1] = 255;
           bmp_data[i * 3 + 2] = 255;
       }
       else
       {
           bmp_data[i * 3] = 0;
           bmp_data[i * 3 + 1] = 255;
           bmp_data[i * 3 + 2] = 0;
       }
   }

   status = UploadDisplayDataRgb(bmp_data, 432);
   if(status)
    {
        StatusBar->SetLabelText("Bitmap load failed");
    }
    else
    {
        StatusBar->SetLabelText("Bitmap load is successful");
    }
}

void indoor_display_testFrame::OnBtnSetColorClick(wxCommandEvent& event)
{
    unsigned long status;
    unsigned char red, green, blue;

    red = ColourPickerCtrl->GetColour().Red();
    green = ColourPickerCtrl->GetColour().Green();
    blue = ColourPickerCtrl->GetColour().Blue();

    status = SetDefaultColor(red, green, blue);
    if(status)
    {
        StatusBar->SetLabelText("Default color setting failed");
    }
    else
    {
        StatusBar->SetLabelText("Default color setting is successful");
    }
}

void indoor_display_testFrame::OnBtnGetColorClick(wxCommandEvent& event)
{
    unsigned long status;
    unsigned char red, green, blue;
    wxColor rgb_color;

    status = GetDefaultColor(&red, &green, &blue);
    if(status == 0)
    {
        rgb_color = (unsigned long)(blue) * 0x10000 + (unsigned long)(green) * 0x100 + red;
        ColourPickerCtrl->SetColour(rgb_color);
        StatusBar->SetLabelText("Default color is successful read");
    }
    else
    {
        StatusBar->SetLabelText("Default color reading failed");
    }
}

void indoor_display_testFrame::OnBtnBmpMonoClick(wxCommandEvent& event)
{
    unsigned long status;
    unsigned char bmp_data[50] = {0xFE, 0x02, 0x02, 0x02, 0x02, 0x00,
                                  0xFE, 0x92, 0x92, 0x92, 0x82, 0x00,
                                  0xFE, 0x82, 0x82, 0x44, 0x38, 0x00};
    status = UploadDisplayDataMono(bmp_data, 18);
    if(status)
    {
        StatusBar->SetLabelText("Bitmap load failed");
    }
    else
    {
        StatusBar->SetLabelText("Bitmap load is successful");
    }
 }

void indoor_display_testFrame::OnBtnSetConfClick(wxCommandEvent& event)
{
    unsigned long status;
    long brightness;

    if(!TxtBright->GetValue().ToLong(&brightness))
    {
        StatusBar->SetLabelText("Enter number from 0 to 100");
    }
    else
    {
        if(brightness > 100 || brightness < 0)
        {
            StatusBar->SetLabelText("Enter number from 0 to 100");
        }
        else
        {
            //display have 1 row of RGB modules and 3 RGB modules in row
            status = SetDisplayConfig(1, 3, brightness);
            if(status)
            {
                StatusBar->SetLabelText("Brightness setting failed");
            }
            else
            {
                StatusBar->SetLabelText("Brightness setting is successful");
            }
        }
    }
}

void indoor_display_testFrame::OnBtnCloseClick(wxCommandEvent& event)
{
    unsigned char status;

    status = DisplayClose();
    if(status)
    {
        StatusBar->SetLabelText("Display did not disconnect");
    }
    else
    {
        StatusBar->SetLabelText("Display disconnected");
    }
}

void indoor_display_testFrame::OnBtnLoadFileClick(wxCommandEvent& event)
{
    unsigned long status = 1;

    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString,("Bmp files (*.bmp)|*.bmp"),	wxFD_OPEN, wxDefaultPosition);

    wxString CurrentDocPath;

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		CurrentDocPath = OpenDialog->GetPath();

		status = UploadDisplayBmp(CurrentDocPath);

	}

    if(status == 0)
    {
        StatusBar->SetLabelText("Bitmap sent to display");
    }
    else
    {
        StatusBar->SetLabelText("Bitmap did not send to display");
    }

	OpenDialog->Destroy();
}



void indoor_display_testFrame::OnBtnFwVerClick(wxCommandEvent& event)
{
    unsigned long status;
    int hw_ver, fw_ver;
    wxString hw_ver_str, fw_ver_str;

    status = GetDisplayVersion((uint32_t*)&hw_ver, (uint32_t*)&fw_ver);
    if(status)
        StatusBar->SetLabelText("Display version did not read");
    else
    {
        hw_ver_str << hw_ver;
        fw_ver_str << fw_ver;
        StatusBar->SetLabelText("HW ver = " + hw_ver_str + " FW ver = " + fw_ver_str);
    }
}

void indoor_display_testFrame::OnBtnDllVerClick(wxCommandEvent& event)
{
    const char *dll_version;

    dll_version = GetDllVersionStr();
    wxString dll_ver_str(dll_version);
    StatusBar->SetLabelText("DLL version = " + dll_ver_str);
}

void indoor_display_testFrame::OnBtnGetConfClick(wxCommandEvent& event)
{
    unsigned long status;
    int m_r_nr, m_c_nr, m_bright;
    wxString m_r_nr_str, m_c_nr_str, m_bright_str;

    status = GetDisplayConfig((uint32_t*)&m_r_nr, (uint32_t*)&m_c_nr, (uint32_t*)&m_bright);
    if(status)
        StatusBar->SetLabelText("Display configuration did not read");
    else
    {
        m_r_nr_str << m_r_nr;
        m_c_nr_str << m_c_nr;
        m_bright_str << m_bright;
        TxtBright->SetValue(m_bright_str);
        StatusBar->SetLabelText("Rows number = " + m_r_nr_str + " Columns number = " + m_c_nr_str);
    }
 }
