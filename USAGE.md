<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Installation](#installation)
- [Understanding Userdive iOS SDK operation mode](#understanding-userdive-ios-sdk-operation-mode)
  - [Developer mode](#developer-mode)
  - [Tracking mode](#tracking-mode)
- [Integrate with your app](#integrate-with-your-app)
  - [Preparing integration](#preparing-integration)
    - [Check your Team ID](#check-your-team-id)
    - [Check your Bundle ID](#check-your-bundle-id)
  - [Capturing image](#capturing-image)
    - [Capture screenshot when it detects screen transitions](#capture-screenshot-when-it-detects-screen-transitions)
    - [Capture screenshots manually](#capture-screenshots-manually)
  - [Tracking gestures](#tracking-gestures)
    - [Automatically detect screen transitions](#automatically-detect-screen-transitions)
    - [Manually view transitions](#manually-view-transitions)
  - [Using custom parameters](#using-custom-parameters)
  - [Using custom screen name](#using-custom-screen-name)
  - [Using location heatmap](#using-location-heatmap)
- [Trouble shooting](#trouble-shooting)
  - [SDK does not record any logs](#sdk-does-not-record-any-logs)
  - [Show tap heatmaps without screen image](#show-tap-heatmaps-without-screen-image)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->



# Installation

Write Podfile to your project.

```
pod 'Userdive-iOS-SDK', '~> 1.0'
```

Install pods.

```
pod install
```

And open workspace.

```
open YourProject.xcworkspace
```


# Understanding Userdive iOS SDK operation mode

SDK has 2 operation modes, which are the following:

* Developer mode
* Tracking mode


## Developer mode

**WARNING: DO NOT USE THIS MODE FOR APPS IN PRODUCTION**

In developer mode, USERDIVE tracks some native views (UIViewController, UIActionSheet, UIAlertView etc.) for heatmap background image.
Confirmation dialog shows after every transition. Tap `Send` button to upload screen image on USERDIVE.


## Tracking mode

USERDIVE tracks user's gesture and transitions in tracking mode.
Those logs will be uploaded when the app enters to background.


# Integrate with your app

## Preparing integration

### Check your Team ID

Check your Team ID at [USERDIVE For Apps website](https://detector.userdive.com/en/apps/).

![team id](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_cHdTUGpOX0IyU2M)


### Check your Bundle ID

Check Bundle ID on Xcode and USERDIVE.

![bundle id settings on USERDIVE](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_WWVGaFdSMHNFMGs)

![bundle id on Xcode](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_Tno4VHA4Snh3alE)

## Capturing image

Before using USERDIVE heatmap, capture the screenshot.
To capture the screenshot, start USERDIVE iOS SDK with developer mode


### Capture screenshot when it detects screen transitions

USERDIVE iOS SDK can automatically track user gesture, and screen 
transitions, if you use standard iOS UI components (UINavigationController, 
UITabBarController etc...).

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START DEVELOPER MODE
  [Userdive startDeveloperMode:<your team id>];

  return YES;
}
```


### Capture screenshots manually

You need to capture the screenshot manually.
if you use custom view or 3rd party framework like a [Unity](https://unity3d.com/jp).

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START DEVELOPER MODE WITHOUT TRACKERS
  [Userdive startDeveloperMode:<your team id> trackers:nil];

  return YES;
}
```

When the screenshot you want to capture is displayed, call the capture method.

Call `updateScreen` to prepare for capture the screen.
When you call `updateScreen` again, upload the captured image (You need to call `updateScreen` twice).

```objective-c
- (void)viewDidAppear:(BOOL)animated
{
  [super viewDidAppear:animated];

  [Userdive updateScreen];
  [Userdive setScreenName:@"screen A"];
}
```


## Tracking gestures

### Automatically detect screen transitions

USERDIVE iOS SDK can track user gesture and view transitions automatically.
To start tracking, call `startTrackingMode:` when initializing SDK.

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID>]` 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [Userdive setLogEnabled:YES];
    [Userdive startTrackingMode:<your team id>];  // <-- HERE

    return YES;
}
```

### Manually view transitions

In the case of an adopted, special view configuration (nonstandard 
view placement and third-party libraries, etc.), you may want to 
consider switching to manual screen transitions

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID> trackers:nil]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START TRACKING MODE WITHOUT TRACKERS
  [Userdive startTrackingMode:<your team id> trackers:nil];

  return YES;
}
```

Call `updateScreen` to change tracking view instance.
And call `setScreenName` to set name of screen.

```objective-c
- (void)viewDidAppear:(BOOL)animated
{
  [super viewDidAppear:animated];

  [Userdive updateScreen];
  [Userdive setScreenName:@"screen A"];
}
```


## Using custom parameters

You can set custom parameter for filterting on analytics view.
For instance, customer's age, gender, living area ... etc.

Up to 5 parameters can be set for USERDIVE.
To set the parameters, enter any string to the method.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // snip

  // custom parameter (up to 5)
  [Userdive setCustomField1:@"25"];    // user age
  [Userdive setCustomField2:@"male"];  // gender

  return YES;
}
```


## Using custom screen name

Set custom screen name in some ViewController.

```objective-c
- (void)viewDidLoad 
{
  [super viewDidLoad];

  [Userdive setScreenName:@"custom screen name"];  // custom screen name
}
```


## Using location heatmap

USERDIVE iOS SDK DOES NOT get user location automatically.
Set values from `CLLocation` object from delegate method of `CLLocationManagerDelegate` in your app.

To use location heatmap, call method below.

```objective-c
/**
 * Note:
 * USERDIVE iOS SDK does not link the CoreLocation framework.
 * Obtains the location information in the application,
 * you must pass the latitude and longitude to USERDIVE.
 */
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    CLLocation *location = locations[0];

    [Userdive setLatitude:location.coordinate.latitude
                longitude:location.coordinate.longitude
       horizontalAccuracy:location.horizontalAccuracy
         verticalAccuracy:location.verticalAccuracy];
}
```


# Trouble shooting

## SDK does not record any logs

First, check your team id and app identifier.
Both values must match on detector.userdive.com.


## Show tap heatmaps without screen image

You must upload screen capture with developer mode.
Need to add `[Userdive startDeveloperMode:<your team id>]` into `AppDelegate.m` .
