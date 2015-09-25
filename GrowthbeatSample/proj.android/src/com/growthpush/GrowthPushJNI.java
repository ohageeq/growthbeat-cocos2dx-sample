package com.growthpush;

import com.growthpush.model.Environment;

public class GrowthPushJNI {

	public static void requestRegistrationId(final String senderId, final int environment) {
		GrowthPush.getInstance().requestRegistrationId(senderId, convertIntToEnvironment(environment));
	}

	public static void trackEvent(final String name) {
		trackEvent(name, null);
	}

	public static void trackEvent(final String name, final String value) {
		GrowthPush.getInstance().trackEvent(name, value);
	}

	public static void setTag(final String name) {
		setTag(name, null);
	}

	public static void setTag(final String name, final String value) {
		GrowthPush.getInstance().setTag(name, value);
	}

	public static void setDeviceTags() {
		GrowthPush.getInstance().setDeviceTags();
	}

	public static Environment convertIntToEnvironment(int environment) {

		switch (environment) {
		case 1:
			return Environment.development;
		case 2:
			return Environment.production;
		default:
			return null;
		}

	}

}
