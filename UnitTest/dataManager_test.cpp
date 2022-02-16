#include "pch.h"
#include "../FriendsProject/dataManager.h"
#include "../FriendsProject/dataManager.cpp"


TEST(dataManagerTest, employeeNumMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211});  //사원번호가 i인 사람 생성
	};  

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.employeeNumMap.find(i);
		EXPECT_NE(iter, data_manager.employeeNumMap.end());
	}
}

TEST(dataManagerTest, givenNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, to_string(i), "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //givenname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.givenNameMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.givenNameMap.end());
	}
}

TEST(dataManagerTest, familyNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", to_string(i), static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //familyname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.familyNameMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.familyNameMap.end());
	}
}

TEST(dataManagerTest, clMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>((i % 3) + 1), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //cl이 i%3+1인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.clMap.find(static_cast<CareerLevel>(i % 3 + 1));
		EXPECT_NE(iter, data_manager.clMap.end());
	}
}

TEST(dataManagerTest, phoneNumMidMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), i, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //사원번호가 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.phoneNumMidMap.find(i);
		EXPECT_NE(iter, data_manager.phoneNumMidMap.end());
	}
}

TEST(dataManagerTest, phoneNumEndMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, i, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.phoneNumEndMap.find(i);
		EXPECT_NE(iter, data_manager.phoneNumEndMap.end());
	}
}


TEST(dataManagerTest, birthYearMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, i, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.birthYearMap.find(i);
		EXPECT_NE(iter, data_manager.birthYearMap.end());
	}
}


TEST(dataManagerTest, birthMonthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, i, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.birthMonthMap.find(i);
		EXPECT_NE(iter, data_manager.birthMonthMap.end());
	}
}

TEST(dataManagerTest, birthDayMapTest) {
	
	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, i, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.birthDayMap.find(i);
		EXPECT_NE(iter, data_manager.birthDayMap.end());
	}
}

TEST(dataManagerTest,certiMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, static_cast<CERTI>(i%4), "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.certiMap.find(static_cast<CERTI>(i % 4));
		EXPECT_NE(iter, data_manager.certiMap.end());
	}
}

TEST(dataManagerTest, nameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, to_string(i), "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.nameMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.nameMap.end());
	}
}

TEST(dataManagerTest, phoneNumMap) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", to_string(i), 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.phoneNumMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.phoneNumMap.end());
	}
}

TEST(dataManagerTest, birthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", i });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.birthMap.find(i);
		EXPECT_NE(iter, data_manager.birthMap.end());
	}
}

