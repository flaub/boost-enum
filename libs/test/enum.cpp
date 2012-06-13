///////////////////////////////////////////////////////////////////////////////
// enum.cpp: a few simple BOOST_ENUM tests
//
// Copyright 2005 Frank Laub
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <iomanip>
#include <functional>
#include <boost/enum.hpp>
#include <boost/concept_check.hpp>
#include <boost/function.hpp>
#include <boost/array.hpp>
#include <boost/type_traits/is_base_of.hpp>

using namespace std;

struct Log
{
	BOOST_ENUM_VALUES(Level, const char*,
		(Abort)("unrecoverable problem") 
		(Error)("recoverable problem")   
		(Alert)("unexpected behavior") 
		(Info) ("expected behavior") 
		(Trace)("normal flow of execution") 
		(Debug)("detailed object state listings") 
	)
};

namespace expanded
{
	class Level : public boost::detail::enum_base<Level, string>
	{
	public:
		enum domain
		{
			Abort,
			Error,
			Alert,
			Info,
			Trace,
			Debug,
		};

		BOOST_STATIC_CONSTANT(index_type, size = 6);

		Level() {}
		Level(domain index) : boost::detail::enum_base<Level, string>(index) {}

		typedef boost::optional<Level> optional;
		static optional get_by_name(const char* str)
		{
			if(strcmp(str, "Abort") == 0) return optional(Abort);
			if(strcmp(str, "Error") == 0) return optional(Error);
			if(strcmp(str, "Alert") == 0) return optional(Alert);
			if(strcmp(str, "Info") == 0) return optional(Info);
			if(strcmp(str, "Trace") == 0) return optional(Trace);
			if(strcmp(str, "Debug") == 0) return optional(Debug);
			return optional();
		}

	private:
		friend class boost::detail::enum_base<Level, string>;
		static const char* names(domain index)
		{
			switch(index)
			{
			case Abort: return "Abort";
			case Error: return "Error";
			case Alert: return "Alert";
			case Info: return "Info";
			case Trace: return "Trace";
			case Debug: return "Debug";
			default: return NULL;
			}
		}

		typedef boost::optional<value_type> optional_value;
		static optional_value values(domain index)
		{
			switch(index)
			{
			case Abort: return optional_value("unrecoverable problem");
			case Error: return optional_value("recoverable problem");
			case Alert: return optional_value("unexpected behavior");
			case Info: return optional_value("expected behavior");
			case Trace: return optional_value("normal flow of execution");
			case Debug: return optional_value("detailed object state listings");
			default: return optional_value();
			}
		}
	};
}

// this macro:
BOOST_ENUM(boolean, 
	(False)
	(True) 
)

// expands to this enum model
namespace expanded
{
	class boolean : public boost::detail::enum_base<boolean>
	{
	public:
		enum domain
		{
			False,
			True,
		};

		BOOST_STATIC_CONSTANT(index_type, size = 2);

	public:
		boolean() {}
		boolean(domain index) : boost::detail::enum_base<boolean>(index) {}

		typedef boost::optional<boolean> optional;
		static optional get_by_name(const char* str)
		{
			if(strcmp(str, "False") == 0) return optional(False);
			if(strcmp(str, "True") == 0) return optional(True);
			return optional();
		}

	private:
		friend class boost::detail::enum_base<boolean>;
		static const char* names(domain index)
		{
			BOOST_ASSERT(static_cast<index_type>(index) < size);
			switch(index)
			{
			case False: return "False";
			case True: return "True";
			default: return "";
			}
		}
	};
}

// from <winuser.h>
//#define VK_SPACE          0x20
//#define VK_PRIOR          0x21
//#define VK_NEXT           0x22
//#define VK_END            0x23
//#define VK_HOME           0x24

// this macro:
BOOST_ENUM_VALUES(VirtualKey, int,
	(Zero) (0)
	(Space)(0x20)
	(Prior)(0x21)
	(Next) (0x22)
	(End)  (0x23)
	(Home) (0x24)
)

// expands to this values model
namespace expanded
{
	class VirtualKey : public boost::detail::enum_base<VirtualKey>
	{
	public:
		enum domain
		{
			Space,
			Prior,
			Next,
			End,
			Home,
		};

		BOOST_STATIC_CONSTANT(index_type, size = 5);

		VirtualKey() {}
		VirtualKey(domain index) : boost::detail::enum_base<VirtualKey>(index) {}

		typedef boost::optional<VirtualKey> optional;
		static optional get_by_name(const char* str)
		{
			if(strcmp(str, "Space") == 0) return optional(Space);
			if(strcmp(str, "Prior") == 0) return optional(Prior);
			if(strcmp(str, "Next") == 0) return optional(Next);
			if(strcmp(str, "End") == 0) return optional(End);
			if(strcmp(str, "Home") == 0) return optional(Home);
			return optional();
		}

	private:
		friend class boost::detail::enum_base<VirtualKey>;
		static const char* names(domain index)
		{
			switch(index)
			{
			case Space: return "Space";
			case Prior: return "Prior";
			case Next: return "Next";
			case End: return "End";
			case Home: return "Home";
			default: return NULL;
			}
		}

		typedef boost::optional<value_type> optional_value;
		static optional_value values(domain index)
		{
			switch(index)
			{
			case Space: return optional_value(0x20);
			case Prior: return optional_value(0x21);
			case Next: return optional_value(0x22);
			case End: return optional_value(0x23);
			case Home: return optional_value(0x24);
			default: return optional_value();
			}
		}
	};
}

// from <winuser.h>
//#define MK_LBUTTON          0x0001
//#define MK_RBUTTON          0x0002
//#define MK_SHIFT            0x0004
//#define MK_CONTROL          0x0008
//#define MK_MBUTTON          0x0010

// this macro:
BOOST_BITFIELD(MouseKey, 
	(LeftButton)  (0x0001)
	(RightButton) (0x0002)
	(Shift)       (0x0004)
	(Control)     (0x0008)
	(MiddleButton)(0x0010)
)

// expands to this bitfield model
namespace expanded
{
	class MouseKey : public boost::detail::bitfield_base<MouseKey>
	{
	public:
		enum domain
		{
			LeftButton,
			RightButton,
			Shift,
			Control,
			MiddleButton,
		};

		BOOST_STATIC_CONSTANT(index_type, size = 5);

		MouseKey() {}
		MouseKey(domain index) : boost::detail::bitfield_base<MouseKey>(index) {}

		typedef boost::optional<MouseKey> optional;
		static optional get_by_name(const char* str)
		{
			if(strcmp(str, "LeftButton") == 0) return optional(LeftButton);
			if(strcmp(str, "RightButton") == 0) return optional(RightButton);
			if(strcmp(str, "Shift") == 0) return optional(Shift);
			if(strcmp(str, "Control") == 0) return optional(Control);
			if(strcmp(str, "MiddleButton") == 0) return optional(MiddleButton);
			return optional();
		}

	private:
		friend class boost::detail::bitfield_access;
		static const char* names(domain index)
		{
			switch(index)
			{
			case LeftButton: return "LeftButton";
			case RightButton: return "RightButton";
			case Shift: return "Shift";
			case Control: return "Control";
			case MiddleButton: return "MiddleButton";
			default: return NULL;
			}
		}

		typedef boost::optional<value_type> optional_value;
		static optional_value values(domain index)
		{
			switch(index)
			{
			case LeftButton: return optional_value(0x0001);
			case RightButton: return optional_value(0x0002);
			case Shift: return optional_value(0x0004);
			case Control: return optional_value(0x0008);
			case MiddleButton: return optional_value(0x0010);
			default: return optional_value();
			}
		}
	};

	//class WindowStyles
	//{
	//public:
	//	enum domain
	//	{
	//		Overlapped   = 0x00000000,
	//		Popup        = 0x80000000,
	//		Child        = 0x40000000,
	//		Minimize     = 0x20000000,
	//		Visible      = 0x10000000,
	//		Disabled     = 0x08000000,
	//		ClipSiblings = 0x04000000,
	//		ClipChildren = 0x02000000,
	//		Maximize     = 0x01000000,
	//		Caption      = 0x00C00000,
	//		Border       = 0x00800000,
	//		DlgFrame     = 0x00400000,
	//		VScroll      = 0x00200000,
	//		HScroll      = 0x00100000,
	//		SysMenu      = 0x00080000,
	//		ThickFrame   = 0x00040000,
	//		Group        = 0x00020000,
	//		TabStop      = 0x00010000,

	//		MinimizeBox  = 0x00020000,
	//		MaximizeBox  = 0x00010000,
	//	
	//		OverlappedWindow = 
	//			Overlapped | 
	//			Caption |
	//			ThickFrame |
	//			MinimizeBox |
	//			MaximizeBox,

	//		Tiled        = Overlapped,
	//		Iconic       = Minimize,
	//		SizeBox      = ThickFrame,
	//		TiledWindow  = OverlappedWindow,
	//	};
	//};
}

struct Point
{
	Point(int x_, int y_) : x(x_), y(y_) {}
	int x;
	int y;
};

ostream& operator << (ostream& os, const Point& rhs)
{
	os << rhs.x << ", " << rhs.y;
	return os;
}

bool operator == (const Point& lhs, const Point& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

BOOST_ENUM_VALUES(Points, Point,
	(Origin)(Point(0, 0))
	(LeftField)(Point(-100, -100))
)

template <typename T>
void test_iterator()
{
	boost::function_requires<boost::RandomAccessIteratorConcept
		<BOOST_DEDUCED_TYPENAME T::const_iterator> >();

	cout << "iteration begin" << endl;
	copy(T::begin(), T::end(), ostream_iterator<T>(cout, "\n"));
	cout << "iteration end" << endl;
}

template <typename T, typename A>
void test_optional_method(
	const A& arg, 
	const BOOST_DEDUCED_TYPENAME T::optional& expected, 
	const char* method_name,
	const boost::function1<BOOST_DEDUCED_TYPENAME T::optional, A>& method
)
{
	BOOST_DEDUCED_TYPENAME T::optional ret = method(arg);
	cout << method_name << "(" << arg << "): ";
	if(ret)
	{
		BOOST_ASSERT(*ret == *expected);
		cout << *ret << endl;
	}
	else
	{
		BOOST_ASSERT(!expected);
		cout << "failed" << endl;
	}
}

template <typename T>
void test_get_by_name(const std::string& str, const boost::optional<T>& expected)
{
	test_optional_method<T, const char*>(str.c_str(), expected, "get_by_name", &T::get_by_name);
	if(expected)
	{
		stringstream ss;
		ss << str;
		T value;
		ss >> value;
//		cout << "istream: " << value << endl;
		BOOST_ASSERT(value == *expected);
	}
}

template <typename T>
void test_get_by_index(
	BOOST_DEDUCED_TYPENAME T::index_type index, 
	const boost::optional<T>& expected)
{
	test_optional_method<T, BOOST_DEDUCED_TYPENAME T::index_type>(
		index, expected, "get_by_index", &T::get_by_index);
}

template <typename T>
void test_get_by_value(
	BOOST_DEDUCED_TYPENAME T::value_type value, 
	const boost::optional<T>& expected)
{
	test_optional_method<T, BOOST_DEDUCED_TYPENAME T::value_type>(
		value, expected, "get_by_value", &T::get_by_value);
}

template <typename T>
void take_enum(const T& value)
{
	cout << "take: " << value << endl;
}

namespace detail
{
	template <bool is_enum = false>
	struct switch_helper
	{
		template <typename T>
		static void apply(const T& value)
		{
			// this is for bitfields
			// it doesn't really make sense to want to switch on a bitfield value
			// therefore, bitfield_base does not have an index() method.
		}
	};

	template <>
	struct switch_helper<true>
	{
		template <typename T>
		static void apply(const T& value)
		{
			cout << "switch(" << value << "): ";
			switch(value.index())
			{
			case 0:
				cout << "0" << endl;
				break;
			case 1:
				cout << "1" << endl;
				break;
			default:
				cout << "invalid" << endl;
			}		
		}
	};
}

template <typename T>
struct switch_enum
{
	static void apply(const T& value)
	{
		typedef BOOST_DEDUCED_TYPENAME T::value_type value_type;
		typedef boost::detail::enum_base<T, value_type> base_type;
		detail::switch_helper<boost::is_base_of<base_type, T>::value>::apply(value);
	}
};

template <>
struct switch_enum<boolean>
{
	static void apply(const boolean& value)
	{
		switch(value.index())
		{
		case boolean::True:
			cout << "switch(boolean::True)" << endl;
			break;
		case boolean::False:
			cout << "switch(boolean::False)" << endl;
			break;
		default:
			cout << "switch(boolean::invalid)" << endl;
		}
	}
};

template <>
struct switch_enum<Points>
{
	static void apply(const Points& value)
	{
		switch(value.index())
		{
		case Points::Origin:
			cout << "switch(Points::Origin)" << endl;
			break;
		case Points::LeftField:
			cout << "switch(Points::LeftField)" << endl;
			break;
		default:
			cout << "switch(Points::invalid)" << endl;
		}
	}
};

template <typename T>
void test_enum(BOOST_DEDUCED_TYPENAME T::value_type invalid_value)
{
	boost::function_requires<boost::AssignableConcept<T> >();
	boost::function_requires<boost::DefaultConstructibleConcept<T> >();
	boost::function_requires<boost::CopyConstructibleConcept<T> >();
	boost::function_requires<boost::EqualityComparableConcept<T> >();

	cout << "Testing: " << typeid(T).name() << endl;

	test_iterator<T>();

	cout << "begin: " << *T::begin() << endl;
	// the next line causes an expected assertion
	//cout << "end: " << *T::end() << endl;

	T invalid;
	T first = *T::begin();
	T second = T::begin()[1];
	T copy = first;
	T assign;
	assign = first;

	// the next line causes an expected assertion
	//cout << "invalid: " << invalid << endl;
	cout << "first: " << first << endl;
	take_enum(first);
	cout << "second: " << second << endl;
	cout << "copy: " << copy << endl;
	BOOST_ASSERT(copy == first);
	cout << "assign: " << assign << endl;
	BOOST_ASSERT(assign == first);

	cout << "value(first): " << dec << first.value() << endl;
	// the next line causes an expected assertion
	//cout << "value(invalid): " << dec << invalid.value() << endl;

	test_get_by_name(first.str(), BOOST_DEDUCED_TYPENAME T::optional(first));
	test_get_by_name(second.str(), BOOST_DEDUCED_TYPENAME T::optional(second));
	test_get_by_name("foo", BOOST_DEDUCED_TYPENAME T::optional());

	test_get_by_index(0, BOOST_DEDUCED_TYPENAME T::optional(first));
	test_get_by_index(T::size, BOOST_DEDUCED_TYPENAME T::optional());
	test_get_by_value(first.value(), BOOST_DEDUCED_TYPENAME T::optional(first));
	test_get_by_value(invalid_value, BOOST_DEDUCED_TYPENAME T::optional());

	switch_enum<T>::apply(first);
	switch_enum<T>::apply(second);
}

template <typename T>
void test_bitfield(BOOST_DEDUCED_TYPENAME T::value_type invalid_value)
{
	test_enum<T>(invalid_value);

	T all_mask(T::all_mask);
	T not_mask(T::not_mask);

	cout << hex;
	test_get_by_value(all_mask.value(), BOOST_DEDUCED_TYPENAME T::optional(all_mask));
	test_get_by_value(not_mask.value(), BOOST_DEDUCED_TYPENAME T::optional());

	T first = *T::begin();
	T second = T::begin()[1];
	T test;
	test |= first;
	cout << "test |= first: " << test << endl;

	test |= second;
	cout << "test |= second: " << test << endl;

	cout << "all_mask: " << all_mask << endl;
	cout << all_mask << " = 0x" << hex << setw(8) << setfill('0') << all_mask.value() << endl;
	cout << not_mask << " = 0x" << hex << setw(8) << setfill('0') << not_mask.value() << endl;
	cout << "all_mask & first: " << (all_mask & first) << endl;
	cout << "first & second: " << (first & second) << endl; 
	cout << "first | second: " << (first | second) << endl;
	cout << "all_mask[first]: " << all_mask[first] << endl;
	cout << "first[second]: " << first[second] << endl;

	T first_set_second = first;
	bool ret = first_set_second.set(second);
	cout << "first.set(second): " << first_set_second << ", " << ret << endl;
	ret = first_set_second.set(second, false);
	cout << "first.set(second, false): " << first_set_second << ", " << ret << endl;

}

int main(int argc, char* argv[])
{
	boolean bFalse = boolean::False;
	test_enum<boolean>(-1);
	cout << endl;

	test_enum<Log::Level>("foo");
	cout << endl;

	test_enum<VirtualKey>(123456789);
	cout << endl;

	test_bitfield<MouseKey>(0xffffffff);
	MouseKey mkAll = MouseKey::all_mask;
	MouseKey mkLeftControl = MouseKey::LeftButton;
	mkLeftControl.set(MouseKey::Control);
	cout << "mkAll[MouseKey::Control]: " << mkAll[MouseKey::Control] << endl;
	cout << "mkLeft.set(MouseKey::Control): " << mkLeftControl << endl;
	mkLeftControl.reset(MouseKey::Control);
	cout << "mkLeft.reset(MouseKey::Control): " << mkLeftControl << endl;
	cout << endl;

	test_enum<expanded::Level>("foo");
	cout << endl;

	test_enum<Points>(Point(-1,-1));

	return 0;
}
