#include "pch.h"

TEST(dataManagerSizeTest, employeeNumMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211});  //사원번호가 i인 사람 생성
	};  

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.employeeNumMap.find(i);
		EXPECT_NE(iter, data_manager.employeeNumMap.end());
	}
}

TEST(dataManagerSizeTest, givenNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, to_string(i), "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //givenname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++) 
	{
		auto iter = data_manager.NameFisrtMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.NameFisrtMap.end());
	}
}

TEST(dataManagerSizeTest, familyNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", to_string(i), static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //familyname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.NameLastMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.NameLastMap.end());
	}
}

TEST(dataManagerSizeTest, clMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>((i % 3) + 1), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //cl이 i%3+1인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.clMap.find(static_cast<CareerLevel>(i % 3 + 1));
		EXPECT_NE(iter, data_manager.clMap.end());
	}
}

TEST(dataManagerSizeTest, phoneNumMidMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), i, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //사원번호가 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.phoneNumMidMap.find(i);
		EXPECT_NE(iter, data_manager.phoneNumMidMap.end());
	}
}

TEST(dataManagerSizeTest, phoneNumEndMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, i, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++) 
	{
		auto iter = data_manager.phoneNumEndMap.find(i);
		EXPECT_NE(iter, data_manager.phoneNumEndMap.end());
	}
}


TEST(dataManagerSizeTest, birthYearMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, i, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.birthYearMap.find(i);
		EXPECT_NE(iter, data_manager.birthYearMap.end());
	}
}


TEST(dataManagerSizeTest, birthMonthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, i, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.birthMonthMap.find(i);
		EXPECT_NE(iter, data_manager.birthMonthMap.end());
	}
}

TEST(dataManagerSizeTest, birthDayMapTest) {
	
	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, i, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++) 
	{
		auto iter = data_manager.birthDayMap.find(i);
		EXPECT_NE(iter, data_manager.birthDayMap.end());
	}
}

TEST(dataManagerSizeTest,certiMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, static_cast<CERTI>(i%4), "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++) 
	{
		auto iter = data_manager.certiMap.find(static_cast<CERTI>(i % 4));
		EXPECT_NE(iter, data_manager.certiMap.end());
	}
}

TEST(dataManagerSizeTest, nameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, to_string(i), "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.nameMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.nameMap.end());
	}
}

TEST(dataManagerSizeTest, phoneNumMap) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", to_string(i), 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.phoneNumMap.find(to_string(i));
		EXPECT_NE(iter, data_manager.phoneNumMap.end());
	}
}

TEST(dataManagerSizeTest, birthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		bool ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", i });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto iter = data_manager.birthMap.find(i);
		EXPECT_NE(iter, data_manager.birthMap.end());
	}
}

