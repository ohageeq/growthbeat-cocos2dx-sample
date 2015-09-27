//
//  GrowthAnalyticsJNI.java
//  growthanalytics-cocos2dx
//
//  Created by Baekwoo Chung on 2015/02/04.
//  Copyright (c) 2015 SIROK, Inc. All rights reserved.
//
package com.growthbeat.analytics;

import java.util.Map;

import com.growthbeat.Logger;
import com.growthbeat.Preference;
import com.growthbeat.analytics.GrowthAnalytics.Gender;
import com.growthbeat.analytics.GrowthAnalytics.TrackOption;
import com.growthbeat.http.GrowthbeatHttpClient;

public class GrowthAnalyticsJNI {

	public static void track(final String name) {
		GrowthAnalytics.getInstance().track(name, null, null);
	}

	public static void track(final String name, final Map<String, String> properties) {
		GrowthAnalytics.getInstance().track(name, properties);
	}

	public static void track(final String name, final int option) {
		GrowthAnalytics.getInstance().track(name, convertIntToTrackOption(option));
	}

	public static void track(final String name, final Map<String, String> properties, final int option) {
		GrowthAnalytics.getInstance().track(name, properties, convertIntToTrackOption(option));
	}

	public static void track(final String namespace, final String name, final Map<String, String> properties, final int option) {
		GrowthAnalytics.getInstance().track(namespace, name, properties, convertIntToTrackOption(option));
	}

	public static void tag(final String name) {
		GrowthAnalytics.getInstance().tag(name, null);
	}

	public static void tag(final String name, final String value) {
		GrowthAnalytics.getInstance().tag(name, value);
	}

	public static void tag(final String namespace, final String name, final String value) {
		GrowthAnalytics.getInstance().tag(namespace, name, value);
	}

	public static void open() {
		GrowthAnalytics.getInstance().open();
	}

	public static void close() {
		GrowthAnalytics.getInstance().close();
	}

	public static void purchase(int price, String category, String product) {
		GrowthAnalytics.getInstance().purchase(price, category, product);
	}

	public static void setUserId(String userId) {
		GrowthAnalytics.getInstance().setUserId(userId);
	}

	public static void setName(String name) {
		GrowthAnalytics.getInstance().setName(name);
	}

	public static void setAge(int age) {
		GrowthAnalytics.getInstance().setAge(age);
	}

	public static void setGender(int gender) {
		GrowthAnalytics.getInstance().setGender(convertIntToGender(gender));
	}

	public static void setLevel(int level) {
		GrowthAnalytics.getInstance().setLevel(level);
	}

	public static void setDevelopment(boolean development) {
		GrowthAnalytics.getInstance().setDevelopment(development);
	}

	public static void setDeviceModel() {
		GrowthAnalytics.getInstance().setDeviceModel();
	}

	public static void setOS() {
		GrowthAnalytics.getInstance().setOS();
	}

	public static void setLanguage() {
		GrowthAnalytics.getInstance().setLanguage();
	}

	public static void setTimeZone() {
		GrowthAnalytics.getInstance().setTimeZone();
	}

	public static void setTimeZoneOffset() {
		GrowthAnalytics.getInstance().setTimeZoneOffset();
	}

	public static void setAppVersion() {
		GrowthAnalytics.getInstance().setAppVersion();
	}

	public static void setRandom() {
		GrowthAnalytics.getInstance().setRandom();
	}

	public static void setAdvertisingId() {
		GrowthAnalytics.getInstance().setAdvertisingId();
	}

	public static void setBasicTags() {
		GrowthAnalytics.getInstance().setDeviceModel();
		GrowthAnalytics.getInstance().setOS();
		GrowthAnalytics.getInstance().setLanguage();
		GrowthAnalytics.getInstance().setTimeZone();
		GrowthAnalytics.getInstance().setTimeZoneOffset();
		GrowthAnalytics.getInstance().setAppVersion();
	}

	public Logger getLogger() {
		return GrowthAnalytics.getInstance().getLogger();
	}

	public GrowthbeatHttpClient getHttpClient() {
		return GrowthAnalytics.getInstance().getHttpClient();
	}

	public Preference getPreference() {
		return GrowthAnalytics.getInstance().getPreference();
	}

	public static TrackOption convertIntToTrackOption(int trackoption) {
		switch (trackoption) {
		case 1:
			return TrackOption.ONCE;
		case 2:
			return TrackOption.COUNTER;
		default:
			return null;
		}
	}

	public static Gender convertIntToGender(int gender) {
		switch (gender) {
		case 1:
			return Gender.MALE;
		case 2:
			return Gender.FEMALE;
		default:
			return null;
		}
	}
}
