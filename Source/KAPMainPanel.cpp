/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 4 Jan 2022 11:41:14am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPMainPanel.h"

KAPMainPanel::KAPMainPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    mTopPanel = std::make_unique<KAPTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mTopPanel);

    mInputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mInputGainPanel);

    mOutputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH-GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mOutputGainPanel);

    mCenterPanel = std::make_unique<KAPCenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mCenterPanel);

}
KAPMainPanel::~KAPMainPanel()
{

}