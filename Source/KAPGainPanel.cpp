/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 4 Jan 2022 11:42:31am
    Author:  Adrian

  ==============================================================================
*/

#include "KAPGainPanel.h"

KAPGainPanel::KAPGainPanel(KadenzeDelayChorusAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}
KAPGainPanel::~KAPGainPanel()
{

}