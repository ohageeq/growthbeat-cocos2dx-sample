package com.growthbeat;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.os.Bundle;

public class GrowthbeatCocos2dActivity extends Cocos2dxActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		GrowthbeatJNI.setContext(getApplicationContext());
	}

}
