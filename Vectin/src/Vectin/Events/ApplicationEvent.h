#pragma once

#include "Vectin/Events/Event.h"

namespace Vectin {

	class VECTIN_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: mWidth(width), mHeight(height) {}

		inline unsigned int getWidth() const {
			return mWidth;
		}

		inline unsigned int getHeight() const {
			return mHeight;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << "WindowResizeEvent: " << mWidth << ", " << mHeight;
			return stringStream.str();

		}

		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowResize"; }

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int mWidth, mHeight;
	};

	class VECTIN_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class VECTIN_API ApplicationTickEvent : public Event {
	public:
		ApplicationTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class VECTIN_API ApplicationUpdateEvent : public Event {
	public:
		ApplicationUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class VECTIN_API ApplicationRenderEvent : public Event {
	public:
		ApplicationRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

}
