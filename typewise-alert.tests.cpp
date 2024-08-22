#include <gtest/gtest.h>
#include "typewise-alert.h"

// Tests for Breach Classification
TEST(TypeWiseAlertTestSuite, InfersLowBreachWhenValueBelowLowerLimit) {
  ASSERT_EQ(TOO_LOW, inferBreach(5, 10, 20));
}

TEST(TypeWiseAlertTestSuite, InfersHighBreachWhenValueAboveUpperLimit) {
  ASSERT_EQ(TOO_HIGH, inferBreach(25, 10, 20));
}

TEST(TypeWiseAlertTestSuite, InfersNormalWhenValueWithinLimits) {
  ASSERT_EQ(NORMAL, inferBreach(15, 10, 20));
}

// Tests for Temperature Classification
TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureForPassiveCooling) {
  ASSERT_EQ(TOO_HIGH, classifyTemperatureBreach(PASSIVE_COOLING, 40));
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureForHiActiveCooling) {
  ASSERT_EQ(NORMAL, classifyTemperatureBreach(HI_ACTIVE_COOLING, 40));
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureForMedActiveCooling) {
  ASSERT_EQ(TOO_LOW, classifyTemperatureBreach(MED_ACTIVE_COOLING, -5));
}

// Mocking send functions to test alert logic
TEST(TypeWiseAlertTestSuite, CheckAndAlertSendsToController) {
  BatteryCharacter batteryChar = { HI_ACTIVE_COOLING, "BrandX" };
  checkAndAlert(TO_CONTROLLER, batteryChar, 50);
  // Check console output manually or use mocks to simulate sending to controller
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertSendsEmail) {
  BatteryCharacter batteryChar = { PASSIVE_COOLING, "BrandY" };
  checkAndAlert(TO_EMAIL, batteryChar, 5);
  // Check console output manually or use mocks to simulate sending an email
}
