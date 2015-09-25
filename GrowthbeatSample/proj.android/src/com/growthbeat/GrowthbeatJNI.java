package com.growthbeat;

import android.content.Context;

public class GrowthbeatJNI {

	private static Context context;

	public static void setContext(Context context) {
		GrowthbeatJNI.context = context;
	}

	public static void initialize(String applicationId, String credentialId) {
		if (context == null)
			throw new IllegalStateException("Must be setContext.");

		Growthbeat.getInstance().initialize(GrowthbeatJNI.context, applicationId, credentialId);
	}

	public static void start() {
		Growthbeat.getInstance().start();
	}

	public static void stop() {
		Growthbeat.getInstance().stop();
	}

	public static void setLoggerSilent(boolean silent) {
		Growthbeat.getInstance().setLoggerSilent(silent);
	}

}
