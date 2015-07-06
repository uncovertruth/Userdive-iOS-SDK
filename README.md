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


# Understanding Userdive iOS SDK

SDK has 2 operation modes below:

* Developer mode
* Tracking mode


## Developer mode

**WARNING: DON'T USE THIS MODE FOR APPS IN PRODUCTION**

In developer mode, USERDIVE tracks some native views (UIViewController, UIActionSheet, UIAlertView etc.) for heatmap base image in developer mode.
Confirmation dialog shows after every transition. Tap `Send` button to upload screen image on USERDIVE.


## Tracking mode

USERDIVE tracks user's gesture and transitions in tracking mode.
Those logs will be uploaded when the app enters to background.


# Integrate with your app

## Check your Team ID

Check your Team ID at [USERDIVE For Apps website](https://detector.userdive.com/en/apps/).

![team id](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_cHdTUGpOX0IyU2M)


## Check your Bundle ID

Check Bundle ID on Xcode and USERDIVE.

![bundle id settings on USERDIVE](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_WWVGaFdSMHNFMGs)

![bundle id on Xcode](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_Tno4VHA4Snh3alE)


## Implementation

Import Userdive iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID>]` or `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into `AppDeletegate:application:didFinishLaunchingWithOptions:`.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	[Userdive setLogEnabled:YES];
	[Userdive startTrackingMode:<your team id>];  // <-- HERE

	// custom parameter
	[Userdive setCustomField1:@"25"];    // user age
	[Userdive setCustomField2:@"male"];  // gender

	return YES;
}
```

Set custom screen name in some ViewController.

```objective-c
- (void)viewDidLoad 
{
	[super viewDidLoad];

	[Userdive setScreenName:@"custom screen name"];  // custom screen name
}
```

To use location heatmap, call method below.

```objective-c
/**
 * Note:
 * Userdive iOS SDK does not link the CoreLocation framework.
 * Obtains the location information in the application,
 * you must pass the latitude and longitude to Userdive.
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

* Check app logs
* Check your team id and app bundle identifier


# About UNCOVER TRUTH

UNCOVER TRUTH Inc. is the Japan No.1 UI/UX analytics and consulting company providing an analytics tool called "USERDIVE for Apps".
In spite of launched service within a year, more 200 companies utilize this service to improve their UI/UX. Based on our achievements and experiences in Japan, we want to share our experiences to improve all companies who have problems with their UI/UX. Also, we want to make user-friendly services more and more in the world. USERDIVE for Apps is the best UI/UX analytics tool, which enables to confirm every single users' transition in all pages, content read during the stay, by HEAT MAPS, FUNNEL ANALYTICS and PLAY BACK. This UX analytics tool can achieve more effective improvements that are better than the pervious experiences of designers or developers.
