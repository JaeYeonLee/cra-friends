#include "pch.h"
#include "../FriendsProject/dataManager.h"


TEST(dataManagerTest, employeeNumMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", 3, 3112, 2609, 77, 12, 11, ADV });  //사원번호가 i인 사람 생성
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
		bool ret = data_manager.addEmployee({ 15123099, to_string(i), "JHOP", 3, 3112, 2609, 77, 12, 11, ADV });  //givenname이 i인 사람 생성
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", to_string(i), 3, 3112, 2609, 77, 12, 11, ADV});  //familyname이 i인 사람 생성
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, ((i%3)+1), 2609, 77, 12, 11, ADV });  //cl이 i%3+1인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.clMap.find(i);
		EXPECT_NE(iter, data_manager.clMap.end());
	}
}

TEST(dataManagerTest, phoneNumMidMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, i, 2609, 77, 12, 11, ADV });  //사원번호가 i인 사람 생성
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, 3112, i, 77, 12, 11, ADV });
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, 3112, 2609, i, 12, 11, ADV });
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, 3112, 2609, 77, i, 11, ADV });
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, 3112, 2609, 77, 12, i, ADV });
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
		bool ret = data_manager.addEmployee({ 15123099, "VXIHXOTH", "JHOP", 3, 3112, 2609, 77, 12, 11, static_cast<CERTI>(i%4) });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)  //Hash에 잘 저장되었는지 test
	{
		auto iter = data_manager.certiMap.find(static_cast<CERTI>(i % 4));
		EXPECT_NE(iter, data_manager.certiMap.end());
	}
}