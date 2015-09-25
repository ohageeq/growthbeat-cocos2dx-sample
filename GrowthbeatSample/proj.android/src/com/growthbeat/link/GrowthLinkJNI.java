package com.growthbeat.link;

import android.content.Context;
import android.net.Uri;

import com.growthbeat.link.GrowthLink;

public class GrowthLinkJNI {

	private static Context context = null;

	public static void setContext(Context context) {
		GrowthLinkJNI.context = context;
	}

	public static void initialize(String applicationId, String credentialId) {
		if (context == null)
			throw new IllegalStateException("Must be setContext.");
		GrowthLink.getInstance().initialize(GrowthLinkJNI.context, applicationId, credentialId);
	}

	public static void handleOpenUrl(Uri uri) {
		GrowthLink.getInstance().handleOpenUrl(uri);
	}

}
