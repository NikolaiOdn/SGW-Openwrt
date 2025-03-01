/***************************************************************************//**
 * # License
 * 
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is Third Party Software licensed by Silicon Labs from a third party
 * and is governed by the sections of the MSLA applicable to Third Party
 * Software and the additional terms set forth below.
 * 
 ******************************************************************************/

/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2016  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.34 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to Silicon Labs Norway, a subsidiary
of Silicon Labs Inc. whose registered office is 400 West Cesar Chavez,
Austin,  TX 78701, USA solely for  the purposes of creating  libraries 
for its  ARM Cortex-M3, M4F  processor-based devices,  sublicensed and 
distributed  under the  terms and conditions  of the  End User License  
Agreement supplied by Silicon Labs.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information

Licensor:                 SEGGER Software GmbH
Licensed to:              Silicon Laboratories Norway
Licensed SEGGER software: emWin
License number:           GUI-00140
License model:            See Agreement, dated 20th April 2012
Licensed product:         - 
Licensed platform:        Cortex M3, Cortex M4F
Licensed number of seats: -
----------------------------------------------------------------------
File        : WIDGET_Dropdown.c
Purpose     : Example demonstrating the DROPDOWN widget
Requirements: WindowManager - (x)
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
----------------------------------------------------------------------
*/
#include "GUI.h"
#include "FRAMEWIN.h"
#include "DROPDOWN.h"
#include "LISTBOX.h"
#include <stddef.h>

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define SPEED 1000

//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 5)

/*******************************************************************
*
*       static code
*
********************************************************************
*/
/*******************************************************************
*
*       _ShowSeveralFunctions
*/
static void _ShowSeveralFunctions(DROPDOWN_Handle hDropDown) {
  int NumEntries;
  int i;
  int Key;
  int Cnt;
  char ac[] = "-- sec to play with dropdown control";

  Key = 0;
  Cnt = 15;
  //
  // Set focus
  //
  GUI_DispStringAtCEOL("WM_SetFocus", 5, 55);
  GUI_Delay(SPEED * 0.9);
  WM_SetFocus(hDropDown);
  GUI_Delay(SPEED * 0.7);
  //
  // Add strings
  //
  GUI_DispStringAtCEOL("DROPDOWN_AddString", 5, 55);
  GUI_Delay(SPEED * 0.8);
  DROPDOWN_AddString(hDropDown, "English");
  DROPDOWN_AddString(hDropDown, "Deutsch");
  DROPDOWN_AddString(hDropDown, "Fran�ais");
  DROPDOWN_AddString(hDropDown, "Japanese");
  DROPDOWN_AddString(hDropDown, "Italiano");
  DROPDOWN_AddString(hDropDown, "Espa�ol");
  DROPDOWN_AddString(hDropDown, "Other language ...");
  GUI_Delay(SPEED * 0.6);
  //
  // Increment selection
  //
  GUI_DispStringAtCEOL("DROPDOWN_IncSel", 5, 55);
  GUI_Delay(SPEED);
  NumEntries = DROPDOWN_GetNumItems(hDropDown);
  for (i = 0; i < (NumEntries - 2); i++) {
    DROPDOWN_IncSel(hDropDown);
    GUI_Delay(SPEED / 6);
	}
  GUI_Delay(SPEED / 4);
  //
  // Expand dropdown
  //
  GUI_DispStringAtCEOL("DROPDOWN_Expand", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_Expand(hDropDown);
  GUI_Delay(SPEED * 0.75);
  //
  // Add scrollbar
  //
  GUI_DispStringAtCEOL("DROPDOWN_SetAutoScroll", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_SetAutoScroll(hDropDown, 1);
  GUI_Delay(SPEED * 0.75);
  //
  // Set font
  //
  GUI_DispStringAtCEOL("DROPDOWN_SetFont", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_SetFont(hDropDown, &GUI_Font16B_1);
  GUI_Delay(SPEED * 0.75);
  //
  // Set text color
  //
  GUI_DispStringAtCEOL("DROPDOWN_SetTextColor", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_SetTextColor(hDropDown, 0, 0x00BB00);
  DROPDOWN_SetTextColor(hDropDown, 2, GUI_BLACK);
  GUI_Delay(SPEED * 0.75);
  //
  // Set background color
  //
  GUI_DispStringAtCEOL("DROPDOWN_SetBkColor", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_SetBkColor(hDropDown, 0, GUI_YELLOW);
  DROPDOWN_SetBkColor(hDropDown, 2, GUI_RED);
  GUI_Delay(SPEED * 0.75);
  //
  // Delete item
  //
  GUI_DispStringAtCEOL("DROPDOWN_DeleteItem", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_DeleteItem(hDropDown, 5);
  GUI_Delay(SPEED * 0.75);
  //
  // Collapse dropdown
  //
  GUI_DispStringAtCEOL("DROPDOWN_Collapse", 5, 55);
  GUI_Delay(SPEED);
  DROPDOWN_Collapse(hDropDown);
  GUI_Delay(SPEED * 0.75);
  //
  // Decrement selection
  //
  GUI_DispStringAtCEOL("DROPDOWN_DecSel", 5, 55);
  GUI_Delay(SPEED);
  NumEntries = DROPDOWN_GetNumItems(hDropDown);
  for (i = 0; i < (NumEntries - 2); i++) {
    DROPDOWN_DecSel(hDropDown);
    GUI_Delay(SPEED / 6);
	}
  GUI_Delay(SPEED / 4);
  //
  // Let user play with dropdown control
  //
  GUI_DispStringAtCEOL("", 5, 55);
  while (!Key && (Cnt > 0)) {
    ac[0] = '0' + (Cnt / 10);
    ac[1] = '0' + (Cnt-- % 10);
    GUI_DispStringAtCEOL(ac, 5, 40);
    GUI_Delay(1000);
    Key = GUI_GetKey();
  }
  //
  // Delete dropdown widget
  //
  GUI_DispStringAtCEOL("DROPDOWN_Delete", 5, 55);
  GUI_Delay(SPEED * 1.1);
  WM_DeleteWindow(hDropDown);
  GUI_Delay(SPEED * 0.75);
}

/*******************************************************************
*
*       _DemoDropDown
*/
static void _DemoDropDown(void) {
  WM_HWIN hDropDown;

  //
  // Display titel
  //
  GUI_SetBkColor(0xB00000);
  GUI_SetColor(0xFFFFFF);
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_DispStringHCenterAt("Dropdown - Sample", 160, 5);
  GUI_Delay(SPEED / 2);
  //
  // Create listbox
  //
  GUI_SetFont(&GUI_Font8x16);
  GUI_SetTextAlign(GUI_TA_LEFT);
  GUI_DispStringAtCEOL("using", 5, 40);
  GUI_DispStringAtCEOL("DROPDOWN_CreateEx", 5, 55);
  GUI_Delay(SPEED * 0.9);
  hDropDown = DROPDOWN_CreateEx(100, 80, 120, 115-50, WM_HBKWIN, WM_CF_SHOW, 0, 0);
  GUI_Delay(SPEED * 0.75);
  //
  // Show serveral functions of listbox
  //
  _ShowSeveralFunctions(hDropDown);
  //
  // Clear display
  //
  GUI_Clear();
  GUI_Delay(SPEED * 1.5);
}

/*******************************************************************
*
*       _DemoDropDownAsChild
*/
static void _DemoDropDownAsChild(void) {
  WM_HWIN hFrame;
  WM_HWIN hDropDown;

  //
  // Display titel
  //
  GUI_SetBkColor(0xB00000);
  GUI_SetColor(0xFFFFFF);
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_DispStringHCenterAt("Dropdown as child - Sample", 160, 5);
  GUI_Delay(SPEED / 2);
  //
  // Create framewin
  //
  GUI_SetFont(&GUI_Font8x16);
  GUI_SetTextAlign(GUI_TA_LEFT);
  GUI_DispStringAtCEOL("using", 5, 40);
  GUI_DispStringAtCEOL("FRAMEWIN_Create", 5, 55);
  GUI_Delay(SPEED);
  hFrame = FRAMEWIN_Create("DropDown", NULL, WM_CF_SHOW, 80, 80, 160, 140);
  FRAMEWIN_SetFont(hFrame, &GUI_Font16B_ASCII);
  FRAMEWIN_SetActive(hFrame, 1);
  GUI_Delay(SPEED * 0.75);
  //
  // Create listbox
  //
  GUI_DispStringAtCEOL("DROPDOWN_CreateEx", 5, 55);
  GUI_Delay(SPEED);
  hDropDown = DROPDOWN_CreateEx(20, 20, 120, 65, WM_GetClientWindow(hFrame), WM_CF_SHOW, 0, 0);
  GUI_Delay(SPEED * 0.75);
  //
  // Show serveral functions of listbox
  //
  _ShowSeveralFunctions(hDropDown);
  //
  // Delete framewin widget
  //
  GUI_DispStringAtCEOL("WM_DeleteWindow", 5, 55);
  GUI_Delay(SPEED);
  WM_DeleteWindow(hFrame);
  GUI_Delay(SPEED * 0.75);
  //
  // Clear display
  //
  GUI_Clear();
  GUI_Delay(SPEED * 1.5);
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  GUI_Init();
  //
  // Check if recommended memory for the sample is available
  //
  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
    GUI_ErrorOut("Not enough memory available."); 
    return;
  }
  WM_SetDesktopColor(0xB00000);
  GUI_Exec();
  while(1) {
    _DemoDropDown();
    _DemoDropDownAsChild();
  }
}

/*************************** End of file ****************************/

