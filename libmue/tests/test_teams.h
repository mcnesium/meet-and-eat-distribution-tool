#ifndef TEST_TEAMS_H
#define TEST_TEAMS_H

#include <cxxtest/TestSuite.h>

#include "teams.h"
#include "helper.h"


class TestTeamClass : public CxxTest::TestSuite
{
	public:
		void testTeamClass(void)
		{
			mue::Team t1(0);
			mue::Team t2(1);
			mue::Team t3(0);

			TS_ASSERT(t1 < t2);
			TS_ASSERT(t1 != t2);
			TS_ASSERT(t1 == t3);
			TS_ASSERT(mue::Team_id(t1) == 0);

			TS_ASSERT_EQUALS(mue::Team_id(t1), 0);
			TS_ASSERT_EQUALS(t1.id(), 0);
		}

		void testTeamGeneration(void)
		{
			std::vector<mue::Team> teams(std::move(test::make_testteams(9)));

			TS_ASSERT_EQUALS(teams.size(), 9);

			for (unsigned i = 0; i < teams.size(); ++i) {
				TS_ASSERT(teams[i] == i);
			}
		}
};

#endif
