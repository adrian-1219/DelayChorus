/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 4 Jan 2022 11:41:25am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPCenterPanel.h"

KAPCenterPanel::KAPCenterPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar = std::make_unique<KAPCenterPanelMenuBar>(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mMenuBar);

    mFxPanel = std::make_unique<KAPFxPanel>(inProcessor);
    mFxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(*mFxPanel);
}
KAPCenterPanel::~KAPCenterPanel()
{

}