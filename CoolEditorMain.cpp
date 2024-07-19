/***************************************************************
 * Name:      CoolEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    prof hilary (profesorhilary@outlook.com)
 * Created:   2024-07-14
 * Copyright: prof hilary ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "CoolEditorMain.h"
#include <wx/msgdlg.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/regex.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/sstream.h>

//(*InternalHeaders(CoolEditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};



wxString wxbuildinfo( wxbuildinfoformat format ) {
    wxString wxbuild( wxVERSION_STRING );

    if ( format == long_f ) {
        #if defined(__WXMSW__)
        wxbuild << _T( "-Windows" );
        #elif defined(__UNIX__)
        wxbuild << _T( "-Linux" );
        #endif

        #if wxUSE_UNICODE
        wxbuild << _T( "-Unicode build" );
        #else
        wxbuild << _T( "-ANSI build" );
        #endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CoolEditorFrame)
const long CoolEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long CoolEditorFrame::ID_AUINOTEBOOK3 = wxNewId();
const long CoolEditorFrame::ID_PANEL_HOME = wxNewId();
const long CoolEditorFrame::ID_PANEL_EDIT = wxNewId();
const long CoolEditorFrame::ID_PANEL_VIEW = wxNewId();
const long CoolEditorFrame::ID_PANEL_LAYOUT = wxNewId();
const long CoolEditorFrame::ID_PANEL_PROJECT = wxNewId();
const long CoolEditorFrame::ID_PANEL_BUILD = wxNewId();
const long CoolEditorFrame::ID_PANEL_DEBUG = wxNewId();
const long CoolEditorFrame::ID_PANEL_SETTING = wxNewId();
const long CoolEditorFrame::ID_PANEL_HELP = wxNewId();
const long CoolEditorFrame::ID_AUINOTEBOOK4 = wxNewId();
const long CoolEditorFrame::ID_DIRPICKERCTRL1 = wxNewId();
const long CoolEditorFrame::ID_TREECTRL_FILELIST = wxNewId();
const long CoolEditorFrame::ID_PANEL2 = wxNewId();
const long CoolEditorFrame::ID_AUINOTEBOOK2 = wxNewId();
const long CoolEditorFrame::ID_AUINOTEBOOK1 = wxNewId();
const long CoolEditorFrame::ID_PANEL1 = wxNewId();
const long CoolEditorFrame::ID_AUINOTEBOOK5 = wxNewId();
const long CoolEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE( CoolEditorFrame, wxFrame )
    //(*EventTable(CoolEditorFrame)
    //*)
END_EVENT_TABLE()

CoolEditorFrame::CoolEditorFrame( wxWindow* parent, wxWindowID id ) {
    //(*Initialize(CoolEditorFrame)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("CoolEditor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(980,450));
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    AuiNotebookConsolePane = new wxAuiNotebook(this, ID_AUINOTEBOOK3, wxDefaultPosition, wxSize(0,100), wxAUI_NB_DEFAULT_STYLE);
    controlTextCtrl = new wxTextCtrl(AuiNotebookConsolePane, ID_TEXTCTRL1, _("PS C:\\Users\\home> "), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_AUTO_URL|wxTE_CHARWRAP|wxBORDER_NONE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    AuiNotebookConsolePane->AddPage(controlTextCtrl, _("Page name"));
    AuiManager1->AddPane(AuiNotebookConsolePane, wxAuiPaneInfo().Name(_T("ConsolePane")).DefaultPane().Caption(_("Console")).CaptionVisible().MinimizeButton().Position(1).Bottom().DockFixed().TopDockable(false).BestSize(wxSize(0,100)));
    AuiNotebookToolBar = new wxAuiNotebook(this, ID_AUINOTEBOOK4, wxDefaultPosition, wxSize(0,100), wxAUI_NB_WINDOWLIST_BUTTON|wxAUI_NB_CLOSE_ON_ALL_TABS|wxAUI_NB_DEFAULT_STYLE|wxFULL_REPAINT_ON_RESIZE);
    PanelHome = new wxPanel(AuiNotebookToolBar, ID_PANEL_HOME, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxCLIP_CHILDREN, _T("ID_PANEL_HOME"));
    PanelEdit = new wxPanel(AuiNotebookToolBar, ID_PANEL_EDIT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_EDIT"));
    PanelView = new wxPanel(AuiNotebookToolBar, ID_PANEL_VIEW, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_VIEW"));
    PanelLayout = new wxPanel(AuiNotebookToolBar, ID_PANEL_LAYOUT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_LAYOUT"));
    PanelProject = new wxPanel(AuiNotebookToolBar, ID_PANEL_PROJECT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_PROJECT"));
    PanelBuild = new wxPanel(AuiNotebookToolBar, ID_PANEL_BUILD, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_BUILD"));
    PanelDebug = new wxPanel(AuiNotebookToolBar, ID_PANEL_DEBUG, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_DEBUG"));
    PanelSetting = new wxPanel(AuiNotebookToolBar, ID_PANEL_SETTING, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_SETTING"));
    PanelHelp = new wxPanel(AuiNotebookToolBar, ID_PANEL_HELP, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_HELP"));
    AuiNotebookToolBar->AddPage(PanelHome, _("Home"), true);
    AuiNotebookToolBar->AddPage(PanelEdit, _("Edit"));
    AuiNotebookToolBar->AddPage(PanelView, _("View"));
    AuiNotebookToolBar->AddPage(PanelLayout, _("Layout"));
    AuiNotebookToolBar->AddPage(PanelProject, _("Project"));
    AuiNotebookToolBar->AddPage(PanelBuild, _("Build"));
    AuiNotebookToolBar->AddPage(PanelDebug, _("Debug"));
    AuiNotebookToolBar->AddPage(PanelSetting, _("Settings"));
    AuiNotebookToolBar->AddPage(PanelHelp, _("Help"));
    AuiManager1->AddPane(AuiNotebookToolBar, wxAuiPaneInfo().Name(_T("ToolBar")).DefaultPane().Caption(_("Tool Bar")).CaptionVisible(false).PinButton().CloseButton(false).Layer(1).Top().DockFixed().BottomDockable(false).LeftDockable(false).RightDockable(false).BestSize(wxSize(0,100)));
    AuiNotebookManagement = new wxAuiNotebook(this, ID_AUINOTEBOOK2, wxDefaultPosition, wxSize(150,0), wxAUI_NB_DEFAULT_STYLE);
    Panel2 = new wxPanel(AuiNotebookManagement, ID_PANEL2, wxPoint(-3,-50), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    DirPickerCtrl1 = new wxDirPickerCtrl(Panel2, ID_DIRPICKERCTRL1, _T("C:\\Users\\home\\Documents"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL|wxDIRP_SMALL, wxDefaultValidator, _T("ID_DIRPICKERCTRL1"));
    BoxSizer1->Add(DirPickerCtrl1, 0, wxALL|wxEXPAND, 5);
    treeCtrl = new wxTreeCtrl(Panel2, ID_TREECTRL_FILELIST, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_TWIST_BUTTONS|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL_FILELIST"));
    BoxSizer1->Add(treeCtrl, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel2);
    BoxSizer1->SetSizeHints(Panel2);
    AuiNotebookManagement->AddPage(Panel2, _("Files"));
    AuiManager1->AddPane(AuiNotebookManagement, wxAuiPaneInfo().Name(_T("LeftPane")).DefaultPane().Caption(_("Management")).CaptionVisible().Layer(1).Left().TopDockable(false).BestSize(wxSize(150,0)));
    AuiNotebookEditors = new wxAuiNotebook(this, ID_AUINOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_DEFAULT_STYLE);
    AuiManager1->AddPane(AuiNotebookEditors, wxAuiPaneInfo().Name(_T("MainViewPane")).DefaultPane().Caption(_("Editors")).CaptionVisible().MinimizeButton().MaximizeButton().CloseButton(false).Center().DockFixed().TopDockable(false).DestroyOnClose());
    AuiNotebookAside = new wxAuiNotebook(this, ID_AUINOTEBOOK5, wxDefaultPosition, wxSize(150,0), wxAUI_NB_DEFAULT_STYLE|wxFULL_REPAINT_ON_RESIZE);
    Panel1 = new wxPanel(AuiNotebookAside, ID_PANEL1, wxPoint(19,270), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    AuiNotebookAside->AddPage(Panel1, _("Aside"));
    AuiManager1->AddPane(AuiNotebookAside, wxAuiPaneInfo().Name(_T("Aside")).DefaultPane().Caption(_("Side Pane")).CaptionVisible().MinimizeButton().MaximizeButton().PinButton().CloseButton(false).Right().TopDockable(false).BestSize(wxSize(150,0)));
    AuiManager1->Update();
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CoolEditorFrame::OncontrolTextCtrlTextEnter);
    Connect(ID_DIRPICKERCTRL1,wxEVT_COMMAND_DIRPICKER_CHANGED,(wxObjectEventFunction)&CoolEditorFrame::OnDirPickerCtrlDirChanged);
    //*)

    stc = new wxStyledTextCtrl( AuiNotebookEditors, wxID_ANY, wxDefaultPosition, wxSize( -1, -1 ), 0 );
    stc->SetCaret( new wxCaret( stc, 50, -1 ) );
    stc->SetCaretLineVisible( true );
    stc->SetCaretLineBackground( wxColour( 150, 150, 150 ) );
    stc->SetMarginLeft( 20 );
    stc->SetMarginType( 0, 0 );
    setCppStyling();
}

void CoolEditorFrame::setCppStyling() {
    stc->SetLexer( wxSTC_LEX_CPP );
    AuiNotebookEditors->AddPage( stc, _( "Styled Editor" ) );
    wxFont font = wxFont(-1, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T( "Courier" ), wxFONTENCODING_DEFAULT );

    // General settings
    stc->StyleClearAll();

    // Background color
    wxColour backgroundColour( 37, 44, 46 );
    stc->StyleSetBackground( wxSTC_STYLE_DEFAULT, backgroundColour );
    stc->StyleSetBackground( wxSTC_CHARSET_DEFAULT, backgroundColour );
    stc->SetSelBackground( true, wxColour( 60, 60, 60 ) );
    stc->SetSelForeground( true, wxColour( 255, 255, 255 ) );

    // Default text color
    stc->StyleSetForeground( wxSTC_C_UUID, wxColour( 45, 45, 255 ) );
    stc->StyleSetBackground( wxSTC_C_UUID, backgroundColour );

    stc->SetViewWhiteSpace( 1 );

    // Comments
    stc->StyleSetForeground( wxSTC_C_COMMENT, wxColour( 0, 128, 0 ) );       // Green
    stc->StyleSetBackground( wxSTC_C_COMMENT, backgroundColour );
    stc->StyleSetItalic( wxSTC_C_COMMENT, true );
    stc->StyleSetForeground( wxSTC_C_COMMENTLINE, wxColour( 50, 128, 0 ) );   // Green
    stc->StyleSetBackground( wxSTC_C_COMMENTLINE, backgroundColour );
    stc->StyleSetItalic( wxSTC_C_COMMENTLINE, true );
    stc->StyleSetForeground( wxSTC_C_COMMENTDOC, wxColour( 0, 170, 0 ) );    // Green
    stc->StyleSetBackground( wxSTC_C_COMMENTDOC, backgroundColour );
    stc->StyleSetItalic( wxSTC_C_COMMENTDOC, true );

    stc->SetViewEOL( false );

    // Preprocessor directives
    stc->StyleSetForeground( wxSTC_C_PREPROCESSOR, wxColour( 128, 128, 255 ) ); // Light blue
    stc->StyleSetBackground( wxSTC_C_PREPROCESSOR, backgroundColour );
    stc->StyleSetBold( wxSTC_C_PREPROCESSOR, true );

    // Preprocessor directives
    stc->StyleSetForeground( wxSTC_C_HASHQUOTEDSTRING, wxColour( 128, 128, 255 ) ); // Light blue
    stc->StyleSetBackground( wxSTC_C_HASHQUOTEDSTRING, backgroundColour );
    stc->StyleSetBold( wxSTC_C_HASHQUOTEDSTRING, true );

    // Default character styling
    stc->StyleSetForeground( wxSTC_C_IDENTIFIER, wxColour( 200, 255, 200 ) ); // White
    stc->StyleSetBackground( wxSTC_C_IDENTIFIER, backgroundColour );

    // Tried setting up bool but this fixed another bug
    stc->StyleSetForeground( wxSTC_TYPE_BOOLEAN, wxColour( 25, 25, 25 ) ); // White
    stc->StyleSetBackground( wxSTC_TYPE_BOOLEAN, backgroundColour );

    // ...
    stc->StyleSetForeground( wxSTC_ST_BOOL, wxColour( 25, 25, 25 ) ); // White
    stc->StyleSetBackground( wxSTC_ST_BOOL, backgroundColour );

    // Default character styling
    stc->SetWhitespaceBackground( true, backgroundColour );
    stc->SetWhitespaceForeground( true, backgroundColour );

    // Set default bg color
    stc->StyleSetForeground( wxSTC_C_DEFAULT, backgroundColour );

    // Strings
    stc->StyleSetForeground( wxSTC_C_STRING, wxColour( 255, 128, 0 ) );      // Orange
    stc->StyleSetBackground( wxSTC_C_STRING, backgroundColour );
    stc->StyleSetForeground( wxSTC_C_CHARACTER, wxColour( 255, 128, 0 ) );   // Orange
    stc->StyleSetBackground( wxSTC_C_CHARACTER, backgroundColour );
    stc->StyleSetItalic( wxSTC_C_STRING, true );

    // Numbers
    stc->StyleSetForeground( wxSTC_C_NUMBER, wxColour( 255, 255, 0 ) );      // Magenta
    stc->StyleSetBackground( wxSTC_C_NUMBER, backgroundColour );

    // Keywords
    stc->StyleSetForeground( wxSTC_C_WORD, wxColour( 0, 28, 205 ) );        // Blue
    stc->StyleSetBackground( wxSTC_C_WORD, backgroundColour );
    stc->StyleSetBold( wxSTC_C_WORD, true );

    // Classes, types
    stc->StyleSetForeground( wxSTC_C_WORD2, wxColour( 128, 0, 255 ) );       // Purple
    stc->StyleSetBackground( wxSTC_C_WORD2, backgroundColour );

    // Operators
    stc->StyleSetForeground( wxSTC_C_OPERATOR, wxColour( 255, 255, 200 ) );    // Yellow
    stc->StyleSetBackground( wxSTC_C_OPERATOR, backgroundColour );
    stc->StyleSetBold( wxSTC_C_OPERATOR, true );

    // Set fonts
    stc->StyleSetFont( wxSTC_C_WORD, font );
    stc->StyleSetFont( wxSTC_C_WORD2, font );
    stc->StyleSetFont( wxSTC_C_OPERATOR, font );
    stc->StyleSetFont( wxSTC_C_NUMBER, font );
    stc->StyleSetFont( wxSTC_C_CHARACTER, font );
    stc->StyleSetFont( wxSTC_C_IDENTIFIER, font );
    stc->StyleSetFont( wxSTC_C_STRING, font );
    stc->StyleSetFont( wxSTC_C_PREPROCESSOR, font );
    stc->StyleSetFont( wxSTC_C_PREPROCESSORCOMMENT, font );
    stc->StyleSetFont( wxSTC_C_PREPROCESSORCOMMENTDOC, font );
    stc->StyleSetFont( wxSTC_C_COMMENT, font );
    stc->StyleSetFont( wxSTC_C_COMMENTDOC, font );
    stc->StyleSetFont( wxSTC_C_COMMENTDOCKEYWORDERROR, font );
    stc->StyleSetFont( wxSTC_C_COMMENTLINE, font );
    stc->StyleSetFont( wxSTC_C_COMMENTLINEDOC, font );
    stc->StyleSetFont( wxSTC_C_UUID, font );
    //stc->StyleSetFont( wxSTC_C_DEFAULT, font );

    // Load the file
    stc->LoadFile( wxT( "CoolEditorMain.cpp" ) );
}

CoolEditorFrame::~CoolEditorFrame() {
    //(*Destroy(CoolEditorFrame)
    //*)
}

void CoolEditorFrame::OnQuit( wxCommandEvent& event ) {
    Close();
}

void CoolEditorFrame::OnAbout( wxCommandEvent& event ) {
    wxString msg = wxbuildinfo( long_f );
    wxMessageBox( msg, _( "Welcome to..." ) );
}

void CoolEditorFrame::OnDirPickerCtrlDirChanged( wxFileDirPickerEvent& event ) {
    // Get the selected path from the DirPickerCtrl
    wxString selectedPath = DirPickerCtrl1->GetPath();

    // Clear existing items from the tree
    treeCtrl->DeleteAllItems();

    // Add the root item with the selected path
    wxTreeItemId root = treeCtrl->AddRoot( selectedPath );

    // Declare the recursive lambda function before use
    std::function<void( const wxString&, wxTreeItemId )> PopulateSubdirectories;
    PopulateSubdirectories = [&]( const wxString & path, wxTreeItemId parent ) {
        wxDir dir( path );

        if ( dir.IsOpened() ) {
            wxString filename;
            bool cont = dir.GetFirst( &filename );

            while ( cont ) {
                if ( filename != "." && filename != ".." ) {
                    wxString filepath = wxFileName::DirName( path ).GetFullPath() + wxFileName::GetPathSeparator() + filename;

                    if ( wxDirExists( filepath ) ) {
                        wxTreeItemId child = treeCtrl->AppendItem( parent, filename, 0 );
                        PopulateSubdirectories( filepath, child ); // Recursively add subdirectories

                    } else {
                        treeCtrl->AppendItem( parent, filename, 1 ); // Add files
                    }
                }

                cont = dir.GetNext( &filename );
            }
        }
    };

    // Call the recursive function to populate the tree
    PopulateSubdirectories( selectedPath, root );
}

void CoolEditorFrame::OncontrolTextCtrlTextEnter( wxCommandEvent& event ) {
    // int numOfCaracters = controlTextCtrl->GetSize();
    std::cout << controlTextCtrl->GetLabel() << std::endl;
}

