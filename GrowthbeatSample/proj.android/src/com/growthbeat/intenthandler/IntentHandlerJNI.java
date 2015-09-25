package com.growthbeat.intenthandler;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.json.JSONException;
import org.json.JSONObject;

import com.growthbeat.GrowthbeatCore;
import com.growthbeat.model.CustomIntent;

public class IntentHandlerJNI {

	private static List<IntentHandler> intentHandlers;

	public static void initializeIntentHandlers() {
		intentHandlers = new ArrayList<IntentHandler>();
		GrowthbeatCore.getInstance().setIntentHandlers(intentHandlers);
	}

	public static void addNoopIntentHandler() {
		if (intentHandlers == null)
			throw new IllegalStateException("not initialized.");
		intentHandlers.add(new NoopIntentHandler());
	}

	public static void addUrlIntentHandler() {
		if (intentHandlers == null || GrowthbeatCore.getInstance().getContext() == null)
			throw new IllegalStateException("not initialized.");
		intentHandlers.add(new UrlIntentHandler(GrowthbeatCore.getInstance().getContext()));
	}

	public static void addCustomIntentHandler(final JavaNativeListener listener) {
		if (intentHandlers == null)
			throw new IllegalStateException("not initialized.");
		intentHandlers.add(new IntentHandler() {
			public boolean handle(com.growthbeat.model.Intent intent) {
				if (intent.getType() != com.growthbeat.model.Intent.Type.custom)
					return false;
				Map<String, String> extra = ((CustomIntent) intent).getExtra();
				JSONObject json = new JSONObject();
				for (Map.Entry<String, String> entry : extra.entrySet()) {
					try {
						json.put(entry.getKey(), entry.getValue());
					} catch (JSONException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				listener.onHandled(json.toString());
				return true;
			}
		});
	}

}
