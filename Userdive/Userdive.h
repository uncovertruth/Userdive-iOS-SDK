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

@end
