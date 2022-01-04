/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 4 Jan 2022 11:41:39am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"

KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}
KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{

}