//
//  Userdive.h
//  Userdive
//
//  Copyright (c) 2014 UNCOVER TRUTH Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  Userdive SDK
 */

@interface Userdive: NSObject

/**
 *  Starts tracking mode. This method can be called only once.
 *  Tracking will stop when app is in the background.
 *  A new session will start when the app is returned from background.
 *
 *  @param teamId Your Userdive Team ID
 */
+(void)startTrackingMode:(NSInteger)teamId;

/**
 *  Starts developer mode. This method can be called only once.
 *  During developer mode, SDK shows the confirmation if you want to
 *  upload screen capture whenever screen transitions.
 *
 *  **!important!**
 *    Please do not call this API for release build.
 *
 *  @param teamId Your Userdive Team ID
 */
+(void)startDeveloperMode:(NSInteger)teamId;

/**
 * Output log message for development if set this to TRUE (default is FALSE).
 * This method should be called before the startTrackingMode method.
 *
 * @param flag BOOL
 */
+(void)setLogEnabled:(BOOL)flag;

/**
 *  Pause tracking. To resume, call 'resume'.
 */
+(void)pause;

/**
 *  Resume tracking.
 */
+(void)resume;

/**
 *  Set the app's user custom fields.
 *
 *  @param value The app's user property value string.
 */
+(void)setCustomField1:(NSString*)value;
+(void)setCustomField2:(NSString*)value;
+(void)setCustomField3:(NSString*)value;
+(void)setCustomField4:(NSString*)value;
+(void)setCustomField5:(NSString*)value;

/**
 *  Set the screen name of the viewController.
 *  This method should be called from the viewWillAppear: method.
 *
 *  This method can also be used for webview page.
 *  For this use, This method should be called from the webviewDidFinishLoad:
 *  delegate method and before call of [Userdive webviewDidFinishLoad:].
 *
 *  @param screenName The name of the screen.
 */
+(void)setScreenName:(NSString*)screenName;

/**
 *  Enable tracking page transitions in webview.
 *  Screen Name of Pages in webview is set from URL.
 *  This method should be called from the webviewDidFinishLoad: delegate method.
 */
+(void)webViewDidFinishLoad:(UIWebView*)webView;

/**
 *  Handle NSURLReqeust with `userdive:` scheme.
 *  You can use Userdive iOS SDK from JavaScript space via this method.
 *  This method should be called from the `webView:shouldStartLoadWithRequest:navigationType:` delegate method.
 *
 *  Supported URLs:
 *
 *  - userdive:///setCustomField1?value=<specified value>
 *  - userdive:///setCustomField2?value=<specified value>
 *  - userdive:///setCustomField3?value=<specified value>
 *  - userdive:///setCustomField4?value=<specified value>
 *  - userdive:///setCustomField5?value=<specified value>
 *  - userdive:///setScreenName?value=<specified value>
 *  - userdive:///setLocation?longitude=<longitude>&latitude=<latitude>&horizontalAccuracy=<horizontalAccuracy>&verticalAccuracy=<verticalAccuracy>
 *
 *  @param request NSURLRequest object from `UIWebViewDelegate:webView:shouldStartLoadWithRequest:navigationType:`
 *  @return TRUE=userdive handled your request. FALSE=userdive NOT handled your request.
 */
+(BOOL)handleUserdiveURLRequest:(NSURLRequest *)request;

/**
 * Set user location.
 */
+(void)setLatitude:(double)latitude
         longitude:(double)longitude
horizontalAccuracy:(float)horizontalAccuracy
  verticalAccuracy:(float)verticalAccuracy;

@end
