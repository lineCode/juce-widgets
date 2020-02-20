/*
   Copyright (c) 2019 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "JuceHeader.h"

class PatchButton : public Component, 
	private TextButton::Listener 
{
public:
	PatchButton(int id, std::function<void(int)> clickHandler);

	void setActive(bool active);

	virtual void resized() override;
	//virtual void paint(Graphics& g) override;

	void setColour(int colourId, Colour newColour);
	String getButtonText() const;
	void setButtonText(const String& text);
	void setFavorite(bool isFavorite);

	void setToggleState(bool state);
	bool getToggleState() const;

	virtual void buttonClicked(Button*) override;

private:
	std::function<void(int)> clicked_;
	TextButton button_;
	ImageComponent favoriteIcon_;
	int id_;
	bool active_;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchButton)
};
