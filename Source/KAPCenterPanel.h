/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 4 Jan 2022 11:41:25am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel
    : public KAPPanelBase
{
public:

    KAPCenterPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPCenterPanel();

private:

    std::unique_ptr<KAPCenterPanelMenuBar> mMenuBar;
    std::unique_ptr<KAPFxPanel> mFxPanel;
};