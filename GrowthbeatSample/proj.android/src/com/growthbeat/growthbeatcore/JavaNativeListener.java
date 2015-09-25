package com.growthbeat.growthbeatcore;


public class JavaNativeListener {
	private long delegate;
    public JavaNativeListener(long delegate){
        this.delegate = delegate;
    }
	public native void onHandled(long delegate, String json);
	
	public void onHandled(String json){
		onHandled(this.delegate, json);
    }
}
