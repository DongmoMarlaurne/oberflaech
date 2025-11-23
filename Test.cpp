/**
 * @file Test.cpp
 * @author Sascha Heimfarth
 * @brief Ein Beispiel einer einfachen Form-Anwendung die mithilfe von wxWidgets und libmodio die Hardware per GUI ansteuern lässt.
 */

// Start of wxWidgets "Hello World" Program
#include "wx/wx.h"
#include <wx/msgdlg.h>

#include "TestingUI.h"

#include "../libmodio/modio.h"
#include "../libmodio/ModbusIOException.h"

class TestingUI : public TestingUIBase
{
private:
  modio io;
public:
  TestingUI(): TestingUIBase(nullptr), io("192.168.1.2")
  {}
  void set_out(int address, wxCommandEvent &event)
  {
    wxCheckBox* checkbox = static_cast<wxCheckBox*>(event.GetEventObject());
    if (checkbox->IsChecked())
    {
      this->io.SetBit(address);
    }
    else
    {
      this->io.DelBit(address);
    }
  }
  void io_connect( wxCommandEvent& event ) override
  {}
  void toggle_o1(wxCommandEvent& event) override
  {
    this->set_out(0, event);
  }
  void toggle_o2(wxCommandEvent& event) override
  {
    this->set_out(1, event);
  }
  void toggle_o3(wxCommandEvent& event) override
  {
    this->set_out(2, event);
  }
  void toggle_o4(wxCommandEvent& event) override
  {
    this->set_out(3, event);
  }
  void toggle_o5(wxCommandEvent& event) override
  {
    this->set_out(4, event);
  }
  void toggle_o6(wxCommandEvent& event) override
  {
    this->set_out(5, event);
  }
  void toggle_o7(wxCommandEvent& event) override
  {
    this->set_out(6, event);
  }
  void toggle_o8(wxCommandEvent& event) override
  {
    this->set_out(7, event);
  }
};

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

enum
{
    ID_Hello = 1
};

bool MyApp::OnInit()
{
  try
  {
    TestingUI *frame = new TestingUI();
    frame->Show(true);
    return true;
  }
  catch (Modbus::Exception err)
  {
    switch (err)
    {
      case Modbus::Exception::ConnectError:
        {
          wxMessageBox(wxT("Kann keine Verbindungaufbauen"), wxT("Verbindungsfehler"), wxICON_INFORMATION);
          break;
        }
      default:
        wxMessageBox(wxT("Unbekannter Fehler"));
        break;
    }
  }
  return false;
}
