<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Supported versions](#supported-versions)
- [How to use iOS SDK for Unity](#how-to-use-ios-sdk-for-unity)
  - [Download Unity package](#download-unity-package)
  - [Import](#import)
  - [Usage](#usage)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Supported versions

* Unity 4 or later


# How to use iOS SDK for Unity

## Download Unity package

Download Unity package from our official repository.

* [USERDIVE iOS SDK for Unity](https://github.com/uncovertruth/userdive-ios-sdk-for-unity/archive/v1.0.0.zip)


## Import

Import a unitypackage.

Required files:

- Assets/Plugins/iOS/Userdive.h
- Assets/Plugins/iOS/libUserdive.a
- Assets/Plugins/iOS/UserdivePlugin.m
- Assets/UserDive/Scripts/UserDive.cs
- Assets/UserDive/Scripts/UDObject.cs


## Usage

Using a USERDIVE iOS SDK for Unity from C#

```
// Tracking mode
void UserDive.startTrackingMode(int teamId);
```

```
// Developer mode
void UserDive.startDeveloperMode(int teamId);
```

```
// Enabling `ScreenEventTracker`
// If `ScreenEventTracker` is enabled, `updateScreen()` will be ignored.
void UserDive.enableScreenTracker();
```

```
// Disabling `ScreenEventTracker`
void UserDive.disableScreenTracker();
```

```
// Get `ScreenEventTracker` status.
// It returns `true` when `ScreenEventTracker` is enabled.
bool UserDive.isScreenTrackerEnabled();
```

```
// Pause tracking
// `updateScreen()` will be ignored too.
void UserDive.pause();
```

```
// Resume tracking
void UserDive.resume();
```

```
// Set custom parameter 1
UserDiveSetCustomField1(value);
```

```
// Set custom parameter 2
UserDiveSetCustomField2(value);
```

```
// Set custom parameter 3
UserDiveSetCustomField3(value);
```

```
// Set custom parameter 4
UserDiveSetCustomField4(value);
```

```
// Set custom parameter 5
UserDiveSetCustomField5(value);
```

```
// Transit view
UserDive.updateScreen(string screenName);
```
