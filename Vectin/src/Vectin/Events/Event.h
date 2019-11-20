#pragma once

#include "vnpch.h"
#include "Vectin\Core.h"

namespace Vectin {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }


	class VECTIN_API Event {
		friend class EventDispatcher;
	public:
		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}

		class EventDispatcher {
		public:
			EventDispatcher(Event& event)
				: mEvent(event) {}

			template<typename T, typename F> bool dispatch(const F& func) {
				if (mEvent.getEventType() == T::getStaticType()) {
					mEvent.handled = func(static_cast<T&>(mEvent));
					return true;
				}
				return false;
			}

		private:
			Event& mEvent;

		};

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) {
		return os << event.toString();
	}

}
