/*
  ==============================================================================

    KAPMainPanel.h
    Created: 4 Jan 2022 11:41:14am
    Author:  Adrian

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
    : public KAPPanelBase
{
public:

    KAPMainPanel(KadenzeDelayChorusAudioProcessor* inProcessor);
    ~KAPMainPanel();

    

private:
    std::unique_ptr<KAPTopPanel> mTopPanel;
    std::unique_ptr<KAPGainPanel> mInputGainPanel;
    std::unique_ptr<KAPGainPanel> mOutputGainPanel;
    std::unique_ptr<KAPCenterPanel> mCenterPanel;
};