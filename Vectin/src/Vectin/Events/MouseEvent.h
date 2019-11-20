#pragma once

#include "Vectin/Events/Event.h"

namespace Vectin {

	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: mMouseX(x), mMouseY(y) {}

		template<typename T> inline T getX() const {
			return mMouseX;
		}

		template<typename T> inline T getY() const {
			return mMouseY;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mMouseX, mMouseY;
	};

	class MouseScrolledEvent : public Event {
		MouseScrolledEvent(float xOffset, float yOffset)
			: mXOffset(xOffset), mYOffset(yOffset) {}

		template<typename T> inline T getXOffset() const {
			return mXOffset;
		}

		template<typename T> inline T getYOffset() const {
			return mYOffset;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "MouseScrolledEvent: " << mXOffset << ", " << mYOffset;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float mXOffset, mYOffset;
	};

	class MouseButtonEvent : public Event {
	public:
		inline int getMouseButton() const {
			return mMouseButton;
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
	protected:
		MouseButtonEvent(int button)
			: mMouseButton(button) {}

		int mMouseButton;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "MouseButtonPressedEvent: " << mMouseButton;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "MouseButtonReleasedEvent: " << mMouseButton;
			return stringStream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}