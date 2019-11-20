#pragma once

#include "Vectin/Events/Event.h"

namespace Vectin {

	class KeyEvent : public Event {
	public:
		inline int getKeyCode() const {
			return mKeyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(int keyCode)
			: mKeyCode(keyCode) {}

		int mKeyCode;
	};

	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), mRepeatCount(repeatCount) {}

		inline int getRepeatCount() const {
			return mRepeatCount;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "KeyPressedEvent: " << mKeyCode << "(" << mRepeatCount << " repeats)";
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	private:
		int mRepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "KeyReleasedEvent: " << mKeyCode;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

	class KeyTypedEvent : public KeyEvent {
		KeyTypedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "KeyTypedEvent: " << mKeyCode;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(KeyTypedEvent);

	};

}