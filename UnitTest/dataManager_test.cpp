#include "pch.h"

TEST(dataManagerTest, employeeNumMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211});  //사원번호가 i인 사람 생성
	};  

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::EMPLOYEENUM);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, givenNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, to_string(i), "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //givenname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getStringHashMap(SearchKey::NAME_FIRST);
		auto iter = it->find(to_string(i));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, familyNameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", to_string(i), static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //familyname이 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getStringHashMap(SearchKey::NAME_LAST);
		auto iter = it->find(to_string(i));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, clMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>((i % 3) + 1), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //cl이 i%3+1인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getClHashMap();
		auto iter = it->find(static_cast<CareerLevel>(i % 3 + 1));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, phoneNumMidMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), i, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });  //사원번호가 i인 사람 생성
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::PHONENUM_MID);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, phoneNumEndMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, i, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::PHONENUM_END);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}


TEST(dataManagerTest, birthYearMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, i, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::BIRTH_YEAR);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}


TEST(dataManagerTest, birthMonthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, i, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::BIRTH_MOHTH);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, birthDayMapTest) {
	
	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, i, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::BIRTH_DAY);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest,certiMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, static_cast<CERTI>(i%4), "VXIHXOTH JHOP", "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getCertiHashMap();
		auto iter = it->find(static_cast<CERTI>(i % 4));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, nameMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, to_string(i), "010-3112-2609", 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getStringHashMap(SearchKey::NAME);
		auto iter = it->find(to_string(i));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, phoneNumMap) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", to_string(i), 771211 });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getStringHashMap(SearchKey::PHONENUM);
		auto iter = it->find(to_string(i));
		EXPECT_NE(iter, it->end());
	}
}

TEST(dataManagerTest, birthMapTest) {

	DataManager data_manager;

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		int ret = data_manager.addEmployee({ i, "VXIHXOTH", "JHOP", static_cast<CareerLevel>(3), 3112, 2609, 77, 12, 11, CERTI::ADV, "VXIHXOTH JHOP", "010-3112-2609", i });
	};

	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		auto it = data_manager.getIntHashMap(SearchKey::BIRTH);
		auto iter = it->find(i);
		EXPECT_NE(iter, it->end());
	}
}

