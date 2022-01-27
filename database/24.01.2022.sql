-- MySQL dump 10.13  Distrib 8.0.22, for Linux (x86_64)
--
-- Host: localhost    Database: unigvacrmp
-- ------------------------------------------------------
-- Server version	8.0.22-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `accounts`
--

DROP TABLE IF EXISTS `accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accounts` (
  `pID` int NOT NULL AUTO_INCREMENT,
  `pName` varchar(26) NOT NULL DEFAULT 'None',
  `pKey` varchar(128) NOT NULL DEFAULT '0',
  `pPinCode` int NOT NULL DEFAULT '0',
  `pSex` int NOT NULL DEFAULT '1',
  `pChar` int NOT NULL DEFAULT '14',
  `pCash` int NOT NULL DEFAULT '0',
  `pBCash` int NOT NULL DEFAULT '0',
  `pEmail` varchar(42) NOT NULL DEFAULT 'null',
  `pDateReg` date NOT NULL,
  `pRegIP` varchar(20) NOT NULL DEFAULT '127.0.0.1',
  `pLVL` int NOT NULL DEFAULT '1',
  `pReferal` varchar(26) NOT NULL DEFAULT 'None',
  `pMember` int NOT NULL DEFAULT '0',
  `pModel` int NOT NULL DEFAULT '14',
  `pRang` int NOT NULL DEFAULT '0',
  `pWarnF` int NOT NULL DEFAULT '0',
  `pWarnA` int NOT NULL DEFAULT '0',
  `bAdmin` int NOT NULL DEFAULT '0',
  `pJob` int NOT NULL DEFAULT '0',
  `pVIP` int NOT NULL DEFAULT '0',
  `pExp` int NOT NULL DEFAULT '0',
  `bJail` int NOT NULL DEFAULT '0',
  `bMute` int NOT NULL DEFAULT '0',
  `pJail` int NOT NULL DEFAULT '-1',
  `pMute` int NOT NULL DEFAULT '-1',
  `pLastX` float NOT NULL DEFAULT '0',
  `pLastY` float NOT NULL DEFAULT '0',
  `pLastZ` float NOT NULL DEFAULT '0',
  `bOffJail` int NOT NULL DEFAULT '0',
  `bOffMute` int NOT NULL DEFAULT '0',
  `bBan` int NOT NULL DEFAULT '0',
  `bWarn` int NOT NULL DEFAULT '0',
  `bOffBan` int NOT NULL DEFAULT '0',
  `bOffWarn` int NOT NULL DEFAULT '0',
  `pJailOffMess` varchar(256) NOT NULL DEFAULT 'None',
  `pMuteOffMess` varchar(256) NOT NULL DEFAULT 'None',
  `pBizOffMess` varchar(144) NOT NULL DEFAULT 'None',
  `pHouseOffMess` varchar(144) NOT NULL DEFAULT 'None',
  `pKvartOffMess` varchar(144) DEFAULT 'None',
  `pWarn` int NOT NULL DEFAULT '0',
  `bUnBan` int NOT NULL DEFAULT '0',
  `bUnWarn` int NOT NULL DEFAULT '0',
  `pFSkin` int NOT NULL DEFAULT '1',
  `bYoutube` int NOT NULL DEFAULT '0',
  `pHP` float NOT NULL DEFAULT '100',
  `pARM` float NOT NULL DEFAULT '0',
  `pTruckLVL` int NOT NULL DEFAULT '0',
  `pTruckEXP` int NOT NULL DEFAULT '0',
  `pLastIP` varchar(50) NOT NULL DEFAULT '127.0.0.1',
  `pLastConnect` varchar(50) NOT NULL DEFAULT '23.12.2005 -- 00:00:00',
  `pLicA` int NOT NULL DEFAULT '0',
  `pLicB` int NOT NULL DEFAULT '0',
  `pLicC` int NOT NULL DEFAULT '0',
  `pLicD` int NOT NULL DEFAULT '0',
  `pZakon` int NOT NULL DEFAULT '0',
  `pOffUninviteMess` varchar(144) NOT NULL DEFAULT 'None',
  `pLogo` int NOT NULL DEFAULT '0',
  `pGun` varchar(56) NOT NULL DEFAULT '0,0,0,0,0,0,0,0,0,0,0,0,0',
  `pAmmo` varchar(56) NOT NULL DEFAULT '0,0,0,0,0,0,0,0,0,0,0,0,0',
  `pTipster` int NOT NULL DEFAULT '0',
  `pJobTipster` int NOT NULL DEFAULT '0',
  `pPhoneNumber` int NOT NULL DEFAULT '0',
  `pPhone` int NOT NULL DEFAULT '0',
  `pPhoneCash` int NOT NULL DEFAULT '0',
  `pKPZ` int NOT NULL DEFAULT '-1',
  `pWANTED` int NOT NULL DEFAULT '0',
  `pJP` int NOT NULL DEFAULT '0',
  `pHOSPITAL` int NOT NULL DEFAULT '0',
  `pMetall` int NOT NULL DEFAULT '0',
  `pPatr` int NOT NULL DEFAULT '0',
  `pDrugs` int NOT NULL DEFAULT '0',
  `pLicBiz` int NOT NULL DEFAULT '0',
  `pLicFly` int NOT NULL DEFAULT '0',
  `pLicGun` int NOT NULL DEFAULT '0',
  `pVoen` int NOT NULL DEFAULT '0',
  `pVoenEXP` int NOT NULL DEFAULT '0',
  `R_9MM` int NOT NULL DEFAULT '0',
  `R_USP` int NOT NULL DEFAULT '0',
  `R_DEAGLE` int NOT NULL DEFAULT '0',
  `R_TEK9` int NOT NULL DEFAULT '0',
  `R_USI` int NOT NULL DEFAULT '0',
  `R_MP5` int NOT NULL DEFAULT '0',
  `R_SHOTGUN` int NOT NULL DEFAULT '0',
  `R_SAWED_OF` int NOT NULL DEFAULT '0',
  `R_FIGHT_SHOTGUN` int NOT NULL DEFAULT '0',
  `R_AK47` int NOT NULL DEFAULT '0',
  `R_M4` int NOT NULL DEFAULT '0',
  `R_COUNTRY_RIFLE` int NOT NULL DEFAULT '0',
  `R_SNIPER_RIFLE` int NOT NULL DEFAULT '0',
  `R_SMOKE` int NOT NULL DEFAULT '0',
  `R_GRENADE` int NOT NULL DEFAULT '0',
  `R_MOLOTOV` int NOT NULL DEFAULT '0',
  `pLomka` int NOT NULL DEFAULT '0',
  `pBizID` int NOT NULL DEFAULT '-1',
  `pCarID` int NOT NULL DEFAULT '-1',
  `pHomeID` int NOT NULL DEFAULT '-1',
  `pPodID` int NOT NULL DEFAULT '-1',
  `pKvartID` int NOT NULL DEFAULT '-1',
  `pNeeds` varchar(30) NOT NULL DEFAULT '100,100,100,100',
  `pMask` int NOT NULL DEFAULT '0',
  `pHeal` int NOT NULL DEFAULT '0',
  `pPepsi` int NOT NULL DEFAULT '0',
  `pBackPack` int NOT NULL DEFAULT '0',
  `pSmoke` int NOT NULL DEFAULT '0',
  `pBeer` int NOT NULL DEFAULT '0',
  `pLighter` int NOT NULL DEFAULT '0',
  `pChips` int NOT NULL DEFAULT '0',
  `pFines` int NOT NULL DEFAULT '1',
  `pSumFines` int NOT NULL DEFAULT '10',
  `pFamID` int NOT NULL DEFAULT '-1',
  `pFamRang` int NOT NULL DEFAULT '0',
  `pFAMoffuninvite` varchar(144) NOT NULL DEFAULT 'None',
  `pTelegramId` int NOT NULL DEFAULT '0',
  `pDonate` int NOT NULL DEFAULT '0',
  `pSkills` varchar(144) NOT NULL DEFAULT '0,0,0,0,0,0',
  `bDeveloper` tinyint NOT NULL DEFAULT (0),
  `pIsFSB` tinyint NOT NULL DEFAULT (0),
  `pFSBRank` int NOT NULL DEFAULT '0',
  `bAns` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`pID`)
) ENGINE=InnoDB AUTO_INCREMENT=82 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts`
--

--
-- Table structure for table `anticheats`
--

DROP TABLE IF EXISTS `anticheats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `anticheats` (
  `acID` int NOT NULL DEFAULT '0',
  `acName` varchar(32) NOT NULL DEFAULT 'none',
  `acStatus` int NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `anticheats`
--

LOCK TABLES `anticheats` WRITE;
/*!40000 ALTER TABLE `anticheats` DISABLE KEYS */;
INSERT INTO `anticheats` VALUES (0,'SpeedHack',0),(1,'Teleport in vehicle',0),(2,'AirBreak',0),(3,'OnFoot Crasher',0),(4,'BulletHitType',0);
/*!40000 ALTER TABLE `anticheats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `atms`
--

DROP TABLE IF EXISTS `atms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `atms` (
  `atmID` int NOT NULL AUTO_INCREMENT,
  `atmX` float NOT NULL DEFAULT '0',
  `atmY` float NOT NULL DEFAULT '0',
  `atmZ` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`atmID`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `atms`
--

LOCK TABLES `atms` WRITE;
/*!40000 ALTER TABLE `atms` DISABLE KEYS */;
INSERT INTO `atms` VALUES (1,1826.11,2527.68,15.6825),(2,2053.55,1904.92,-77.2241),(3,2054.63,1904.86,-77.2241),(4,530.216,1721.84,2003.11),(5,531.001,1721.84,2003.11),(6,657.922,2321.7,1504.36),(7,657.922,2320.78,1504.35),(8,2527.84,-2133.52,21.97),(9,2473.48,-727.273,12.3);
/*!40000 ALTER TABLE `atms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bans`
--

DROP TABLE IF EXISTS `bans`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bans` (
  `Nick` varchar(32) NOT NULL,
  `UnbanDate` int NOT NULL,
  `AdminNick` varchar(32) NOT NULL,
  `BanDate` varchar(50) NOT NULL,
  `Type` varchar(10) NOT NULL,
  `Reason` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bans`
--

--
-- Table structure for table `business_profit`
--

DROP TABLE IF EXISTS `business_profit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `business_profit` (
  `id` int NOT NULL AUTO_INCREMENT,
  `bid` int NOT NULL,
  `date` varchar(100) NOT NULL DEFAULT '1.1.2001',
  `money` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4446 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `business_profit`
--

--
-- Table structure for table `bussines`
--

DROP TABLE IF EXISTS `bussines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bussines` (
  `bID` int NOT NULL AUTO_INCREMENT,
  `bOwned` int NOT NULL,
  `bOwner` varchar(32) NOT NULL,
  `bPrice` int NOT NULL,
  `bType` int NOT NULL,
  `bCash` int NOT NULL DEFAULT '0',
  `bProfit` int NOT NULL DEFAULT '0',
  `bExitX` float NOT NULL,
  `bExitY` float NOT NULL,
  `bExitZ` float NOT NULL,
  `bControl` int NOT NULL DEFAULT '0',
  `bEnterPrice` int NOT NULL DEFAULT '0',
  `bFillPrice` int NOT NULL DEFAULT '50',
  `bRepairPrice` int NOT NULL DEFAULT '50',
  `bDays` int NOT NULL DEFAULT '3',
  PRIMARY KEY (`bID`)
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bussines`
--

LOCK TABLES `bussines` WRITE;
/*!40000 ALTER TABLE `bussines` DISABLE KEYS */;
INSERT INTO `bussines` VALUES (4,1,'None',5000000,2,67298,0,1981.2,1893.38,15.528,7,5000,50,50,28),(5,1,'None',30000000,6,28250,0,1911.93,1685.27,15.8325,6,0,76,50,28),(6,0,'None',30000000,5,222250,0,1988.03,1927,15.51,7,0,50,5000,3),(7,0,'None',20000000,1,18136,0,1799.38,2502.6,15.8347,7,0,50,50,3),(8,1,'None',30000000,4,1410998,0,2314.37,1760.11,1.52937,0,0,50,50,27),(9,0,'None',1000000,3,1785,0,1949.89,1899.36,15.5124,0,0,50,50,3),(10,0,'None',1000000,1,5159,0,2127.93,1791.62,12.2616,0,0,50,50,3),(11,0,'None',5000000,5,70160,0,2178.96,-1838.2,18.8143,0,0,50,50,3),(12,0,'None',5000000,6,5285,0,2243.65,-1784.85,21.7092,0,0,50,50,3),(13,0,'None',1000000,3,0,0,2310.72,-1911.74,21.9677,0,0,50,50,3),(14,0,'None',5000000,1,1100,0,2510.05,-2186.42,22.0047,0,0,50,50,3),(15,0,'None',1000000,1,0,0,2619.6,-2449.66,22.0116,0,0,50,50,3),(16,0,'None',1000000,2,0,0,2432.74,-2294.21,22.1016,0,0,50,50,3),(17,0,'None',1000000,2,0,0,2627.86,-1540.85,23.6116,0,0,50,50,3),(18,0,'None',1000000,1,0,0,2555.25,-1763.86,21.9547,0,0,50,50,3),(19,0,'None',5000000,6,0,0,2569.69,-1735.14,21.91,0,0,50,50,3),(20,0,'None',1000000,1,250,0,1867.72,1383.11,9.79886,0,0,50,50,3),(21,1,'None',5000000,4,1636,0,2350.05,-2138.32,22.5854,0,0,50,50,29),(22,0,'None',1000000,2,0,0,2283.08,-2169.84,22.0316,0,0,50,50,3),(23,0,'None',1500000,1,0,0,2370.65,-676.894,12.0547,0,0,50,50,3),(33,0,'None',750000,2,0,0,2111.26,-2316.39,21.95,0,0,50,50,3),(34,0,'None',750000,1,0,0,2119.54,-2348.09,22.2525,0,0,50,50,3),(35,0,'None',1000000,1,0,0,2521.93,-994.645,2.06188,0,0,50,50,3);
/*!40000 ALTER TABLE `bussines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `familys`
--

DROP TABLE IF EXISTS `familys`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `familys` (
  `fID` int NOT NULL AUTO_INCREMENT,
  `fName` varchar(32) NOT NULL,
  `fCreatorID` int NOT NULL,
  `fCreatorName` varchar(32) NOT NULL,
  PRIMARY KEY (`fID`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `familys`
--

--
-- Table structure for table `fines`
--

DROP TABLE IF EXISTS `fines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `fines` (
  `fine_id` int NOT NULL AUTO_INCREMENT,
  `account_id` int NOT NULL DEFAULT '1',
  `fined` varchar(32) NOT NULL DEFAULT 'Unigva RolePlay',
  `fine` int NOT NULL DEFAULT '1',
  `date` varchar(30) NOT NULL,
  `reason` varchar(32) NOT NULL,
  PRIMARY KEY (`fine_id`)
) ENGINE=InnoDB AUTO_INCREMENT=350 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fines`
--

--
-- Table structure for table `freekassa_payments`
--

DROP TABLE IF EXISTS `freekassa_payments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `freekassa_payments` (
  `id` int NOT NULL AUTO_INCREMENT,
  `freekassaId` varchar(255) NOT NULL,
  `account` varchar(255) NOT NULL,
  `sum` float NOT NULL,
  `itemsCount` int NOT NULL DEFAULT '1',
  `dateCreate` datetime NOT NULL,
  `dateComplete` datetime DEFAULT NULL,
  `status` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `freekassa_payments`
--

--
-- Table structure for table `givebankmoney`
--

DROP TABLE IF EXISTS `givebankmoney`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `givebankmoney` (
  `Nick` int NOT NULL,
  `Money` int NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `ip` varchar(20) NOT NULL,
  `time` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `givebankmoney`
--


--
-- Table structure for table `givemoney`
--

DROP TABLE IF EXISTS `givemoney`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `givemoney` (
  `Nick` int NOT NULL,
  `Money` int NOT NULL,
  `Reason` varchar(50) NOT NULL,
  `ip` varchar(20) NOT NULL,
  `time` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `givemoney`
--

--
-- Table structure for table `houses`
--

DROP TABLE IF EXISTS `houses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `houses` (
  `hID` int NOT NULL AUTO_INCREMENT,
  `hExitX` float NOT NULL DEFAULT '0',
  `hExitY` float NOT NULL DEFAULT '0',
  `hExitZ` float NOT NULL DEFAULT '0',
  `hOwned` int NOT NULL DEFAULT '0',
  `hOwner` varchar(32) NOT NULL DEFAULT 'None',
  `hPrice` int NOT NULL DEFAULT '1000',
  `hType` int NOT NULL DEFAULT '1',
  `hDays` int NOT NULL DEFAULT '3',
  `hLock` int NOT NULL DEFAULT '0',
  `car_pos_x` float NOT NULL DEFAULT '0',
  `car_pos_y` float NOT NULL DEFAULT '0',
  `car_pos_z` float NOT NULL DEFAULT '0',
  `car_pos_a` float NOT NULL DEFAULT '0',
  `hPatron` int NOT NULL DEFAULT '0',
  `hDrugs` int NOT NULL DEFAULT '0',
  `hMetall` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`hID`)
) ENGINE=InnoDB AUTO_INCREMENT=145 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `houses`
--

LOCK TABLES `houses` WRITE;
/*!40000 ALTER TABLE `houses` DISABLE KEYS */;
INSERT INTO `houses` VALUES (2,1945.14,1845.31,15.4186,0,'None',1000000,1,3,0,1959.55,1848.77,15.1496,179.869,122,12,13),(3,1985.88,1831.93,16.111,0,'None',1000000,2,3,0,1969.59,1831.2,15.1707,2.157,0,0,0),(4,1989.36,1794.01,15.7392,1,'None',3000000,2,28,0,1968.85,1796.49,15.642,359.002,1,0,0),(5,2019.77,1548.22,20.3344,0,'None',25000000,3,3,0,2008.14,1540.62,15.5741,359.083,0,0,0),(6,2315.17,-652.117,12.8844,0,'None',2500000,3,3,0,2336.63,-625.555,11.8262,92.6023,0,0,0),(7,2330.92,-648.346,12.8844,0,'None',2500000,3,3,0,2335.94,-635.291,11.8266,91.4916,0,0,0),(8,2331.29,-610.099,12.8844,0,'None',2500000,3,3,0,2335.41,-596.824,11.8275,91.5989,0,0,0),(9,2315.15,-613.758,12.8844,0,'None',2500000,3,3,0,2335.35,-586.964,11.8265,91.1067,0,0,0),(10,2283.55,-583.117,12.1163,0,'None',250000,1,3,0,2280.31,-590.618,11.8134,0.697713,0,0,0),(11,2266.73,-586.741,12.1163,0,'None',250000,1,3,0,2270.4,-581.243,11.8029,179.963,0,0,0),(12,2266.46,-603.345,12.1163,0,'None',250000,1,3,0,2270.69,-595.339,11.8103,179.411,0,0,0),(13,2266.46,-620.14,12.1163,0,'None',250000,1,3,0,2270.88,-615.037,11.8165,178.469,0,0,0),(14,2266.46,-636.495,12.1163,0,'None',250000,1,3,0,2270.83,-630.852,11.8154,179.515,0,0,0),(15,2283.52,-632.549,12.1163,0,'None',250000,1,3,0,2280.67,-637.384,11.8039,1.04902,0,0,0),(16,2283.52,-648.929,12.1163,0,'None',250000,1,3,0,2280.83,-653.376,11.8025,358.997,0,0,0),(17,2266.6,-652.635,12.0013,0,'None',250000,1,3,0,2270.68,-646.952,11.8094,179.475,0,0,0),(18,1862.46,2844.57,11.5851,0,'None',2500000,3,3,0,1873.24,2848.42,11.817,180.48,0,0,0),(19,1919.05,2851.64,11.576,0,'None',2000000,3,3,0,1922.05,2840.75,11.8167,91.2991,0,0,0),(20,1918.82,2902.73,12.6844,0,'None',2000000,3,3,0,1923.11,2886.1,11.8166,90.51,0,0,0),(21,1883.79,2870.64,13.0663,0,'None',2000000,3,3,0,1879.07,2889.58,11.8094,269.672,0,0,0),(22,1854.19,2894.51,12.2272,0,'None',2500000,3,3,0,1843.24,2890.39,11.8159,0.558431,0,0,0),(23,1820.62,2897.93,12.7464,0,'None',500000,1,3,0,1816.36,2907.16,11.8058,90.0912,0,0,0),(24,1814.68,2870.86,12.6234,0,'None',750000,2,3,0,1804.18,2865.73,11.7996,359.215,0,0,0),(25,1808.68,2848.77,13.2409,0,'None',750000,2,3,0,1816.83,2831.92,11.8208,90.0262,0,0,0),(26,1830.93,2840.93,12.3021,0,'None',250000,2,3,0,1836.19,2832.33,11.8026,89.1164,0,0,0),(27,-2361.61,2557.23,42.1259,0,'None',500000,2,3,0,-2361.73,2562.47,41.655,1.4412,0,0,0),(28,-2344.81,2556.12,41.723,0,'None',500000,2,3,0,-2345.8,2550.41,41.5087,87.1666,0,0,0),(29,-2356.1,2585.93,42.1866,0,'None',500000,2,3,0,-2359.31,2577.96,41.5887,269.096,0,0,0),(30,-2342.41,2593.46,42.5947,0,'None',500000,2,3,0,-2346.02,2586,41.7819,91.1793,0,0,0),(31,-2358.09,2608.51,42.2245,0,'None',500000,2,3,0,-2348.8,2606.15,41.6292,90.725,0,0,0),(32,-2812.1,-670.524,8.90296,0,'None',15000000,3,3,0,0,0,0,0,0,0,0),(33,465.385,-1249.56,42.0225,0,'None',5000000,2,3,0,460.718,-1246.21,40.5078,339.942,0,0,0),(34,530.987,-1275.54,41.1651,0,'None',5000000,2,3,0,539.706,-1268.34,40.5075,343.298,0,0,0),(35,525.175,-1304.83,41.0904,0,'None',5000000,2,3,0,535.386,-1304.57,40.4595,348.555,0,0,0),(36,589.45,-1290.21,41.9406,0,'None',5000000,2,3,0,593.314,-1291.65,40.5068,339.095,0,0,0),(37,622.38,-1250.21,42.1248,0,'None',5000000,2,3,0,628.314,-1254.21,40.5076,159.892,0,0,0),(38,641.926,-1266.17,41.8311,0,'None',5000000,2,3,0,635.022,-1265.99,40.5073,161.248,0,0,0),(39,628.966,-1320.49,41.458,0,'None',5000000,2,3,0,626.223,-1305.26,40.5066,338.439,0,0,0),(40,720.158,-1351.03,41.008,0,'None',5000000,2,3,0,737.433,-1344.68,40.4833,341.721,0,0,0),(41,2042.94,-1100.24,2.24381,0,'None',2500000,3,3,0,2029.76,-1109.08,1.77801,14.84,0,0,0),(42,2014.11,-1073.97,3.04745,0,'None',2500000,3,3,0,2014.6,-1047.48,1.77641,269.692,0,0,0),(43,2019.74,-982.738,1.61873,0,'None',2500000,3,3,0,2014.71,-1009.2,1.77674,271.147,0,0,0),(44,2052.47,-997.768,3.50006,0,'None',2500000,3,3,0,2052.73,-975.264,1.78051,91.2492,0,0,0),(45,2079.67,-1103.3,3.11537,0,'None',10000000,3,3,0,2103.02,-1098.47,1.77654,9.57407,0,0,0),(46,2150.53,-1070.27,2.16289,0,'None',10000000,3,3,0,2122.77,-1081.58,1.77622,11.3104,0,0,0),(47,2172.72,-1026.47,2.97357,0,'None',2500000,3,3,0,2174.63,-1010.48,1.77658,90.98,0,0,0),(48,2167.58,-998.754,2.32538,0,'None',2500000,3,3,0,2172.21,-976.313,1.78405,91.4775,0,0,0),(49,2172.6,-933.842,2.8314,0,'None',2500000,3,3,0,2174,-957.833,1.78023,90.0288,0,0,0),(50,2122,-1011.95,6.63892,0,'None',15000000,3,3,0,2118.73,-1003.63,1.7768,90.4083,0,0,0),(51,2251.26,-1071.41,2.33273,0,'None',2500000,3,3,0,2223.65,-1074.79,1.77624,0.717867,0,0,0),(52,2305.54,-1086.67,7.02819,0,'None',15000000,3,3,0,2287.35,-1111.05,1.77624,270.56,0,0,0),(53,2459.66,-1016.31,6.45937,1,'None',15000000,3,28,0,2437.49,-1046.62,1.63923,1.58801,276,1490,300),(54,2550.05,-1002.51,2.28831,0,'None',5000000,3,3,0,2572.34,-1006.57,1.77659,2.202,0,0,0),(55,2685.68,-231.282,3.64645,0,'None',250000,1,3,0,2697.35,-228.6,3.77112,2.31478,0,0,0),(56,2627.93,-232.619,3.81796,0,'None',250000,1,3,0,2624.28,-231.483,3.75451,0.708006,0,0,0),(57,2608.14,-200.979,7.21709,0,'None',500000,1,3,0,2603.8,-194.021,6.2682,181.366,0,0,0),(58,2590.42,-230.766,3.79362,0,'None',250000,1,3,0,2594.23,-231.05,3.75657,358.781,0,0,0),(59,2573.58,-230.414,3.36857,0,'None',250000,1,3,0,2578.66,-230.528,3.54964,0.400851,0,0,0),(60,2524.49,-199.004,3.54687,0,'None',250000,1,3,0,2528.74,-200.802,2.89187,180.702,0,0,0),(61,2422.26,-206.304,2.25555,0,'None',250000,1,3,0,2432.85,-204.242,1.91423,181.156,0,0,0),(62,2414.98,-230.587,2.07125,0,'None',250000,1,3,0,2412.01,-231.434,1.83909,359.334,0,0,0),(63,2381.72,-202.434,2.46262,0,'None',250000,1,3,0,2378.34,-204.706,1.91355,181.672,0,0,0),(64,2329.99,-205.192,2.59115,0,'None',750000,2,3,0,2316.17,-207.326,1.94414,180.695,0,0,0),(65,2240.67,-197.006,2.04104,0,'None',1000000,2,3,0,2218.01,-196.217,1.94238,179.05,0,0,0),(66,2204.72,-231.147,1.90042,0,'None',250000,1,3,0,2209.02,-233.531,1.77975,1.84264,0,0,0),(67,2491.49,-955.343,2.75437,1,'None',2500000,3,21,0,2519.29,-956.071,1.77779,180.339,0,0,0),(68,2470.87,-962.752,2.04813,1,'None',2500000,3,28,0,2442.32,-956.784,1.77629,181.376,0,0,0),(69,2394.5,-955.496,2.79437,0,'None',2500000,3,3,0,2417.53,-956.945,1.77769,179.655,0,0,0),(70,2395.51,-1031.88,2.68438,0,'None',2500000,3,3,0,2392.81,-1011.08,1.69002,89.9675,0,0,0),(71,2366.11,-1034.71,2.01,1,'None',750000,2,24,0,2361.75,-1019.67,1.78652,268.527,0,0,0),(72,2364.91,-990.407,2.01,0,'None',750000,2,3,0,2362.41,-1004.35,1.78626,268.834,0,0,0),(73,2340.69,-1075.08,2.68438,0,'None',2500000,3,3,0,2359.11,-1073.51,1.77636,1.08674,0,0,0),(74,2330.01,-1046.29,2.06813,0,'None',750000,2,3,0,2304,-1030.26,1.77612,180.198,0,0,0),(75,2272.39,-1033.58,2.68438,0,'None',2500000,3,3,0,2246.83,-1034.45,1.77645,180.17,0,0,0),(76,2202.3,-1037.41,2.06813,0,'None',2500000,3,3,0,2223.77,-1032.71,1.78321,177.837,0,0,0),(77,2053.26,-1027.72,1.54862,0,'None',2000000,3,3,0,2057.47,-1046.92,1.77636,91.513,0,0,0),(78,2838.47,-1725.67,3.78437,0,'None',5000000,3,3,0,2838.62,-1714.59,2.70628,90.2968,0,0,0),(79,2838.68,-1691.65,3.78437,0,'None',5000000,3,3,0,2836.3,-1681.12,2.70657,90.2263,0,0,0),(80,2838.34,-1657.96,3.78437,0,'None',5000000,3,3,0,2837.84,-1647.04,2.70658,91.5948,0,0,0),(81,2838.48,-1624.87,3.78437,0,'None',5000000,3,3,0,2837.74,-1613.72,2.70657,90.7422,0,0,0),(82,2839.29,-1591.26,3.78437,0,'None',5000000,3,3,0,2837.8,-1580.1,2.70632,91.0536,0,0,0),(83,2358.45,-644.908,12.002,0,'None',250000,1,3,0,2361.17,-652.549,11.7759,92.4332,0,0,0),(84,2358.79,-626.171,12.002,0,'None',250000,1,3,0,2361.11,-631.503,11.7782,89.9687,0,0,0),(85,2358.35,-606.894,12.002,0,'None',250000,1,3,0,2361.38,-611.916,11.7782,88.5311,0,0,0),(86,2358.9,-586.98,12.0042,0,'None',250000,1,3,0,2360.06,-591.912,11.7785,90.3966,0,0,0),(87,2283.35,-599.51,12.0013,0,'None',250000,1,3,0,2280.42,-605.285,11.8094,0.496524,0,0,0),(88,2283.52,-616.483,12.1163,0,'None',250000,1,3,0,2280.53,-620.529,11.8055,0.08178,0,0,0),(89,2233.45,-583.073,12.2569,0,'None',250000,1,3,0,2229.71,-588.911,11.811,1.41868,0,0,0),(90,2215.88,-586.716,12.2484,0,'None',250000,1,3,0,2219.89,-581.699,11.8059,180.026,0,0,0),(91,2233.52,-599.488,12.1163,0,'None',250000,1,3,0,2229.71,-604.485,11.8108,358.153,0,0,0),(92,2215.93,-603.535,12.1163,0,'None',250000,1,3,0,2219.77,-597.414,11.8042,179.19,0,0,0),(93,2215.96,-619.993,12.1163,0,'None',250000,1,3,0,2219.8,-610.624,11.8053,179.566,0,0,0),(94,2233.52,-615.945,12.1163,0,'None',250000,1,3,0,2229.88,-621.594,11.805,0.494726,0,0,0),(95,2233.73,-632.39,12.2569,0,'None',250000,1,3,0,2229.92,-637.779,11.8047,359.006,0,0,0),(96,2216.16,-636.234,12.0013,0,'None',250000,1,3,0,2220.29,-626.531,11.8205,181.87,0,0,0),(97,2233.43,-648.708,12.1163,0,'None',250000,1,3,0,2229.78,-653.012,11.8084,359.621,0,0,0),(98,2216.02,-652.359,12.1163,0,'None',250000,1,3,0,2220.4,-646.867,11.8294,177.902,0,0,0),(99,1749.92,2188.96,15.8666,0,'None',1500000,2,3,0,1766.67,2190.52,15.817,181.57,0,0,0),(100,1864.82,1419.32,10.2651,0,'None',250000,1,3,0,1872.45,1427.41,9.5372,178.36,0,0,0),(101,1866.02,1439.87,10.1865,0,'None',750000,2,3,0,1872.36,1449.63,9.53206,178.119,0,0,0),(102,1859.47,1405.15,9.75565,0,'None',250000,1,3,0,1871.56,1400.99,9.49119,176.969,0,0,0),(103,1865.32,1358.45,10.0435,0,'None',250000,1,3,0,1872.01,1365.81,9.51558,179.595,0,0,0),(104,1865.97,1337.13,10.3209,0,'None',250000,1,3,0,1871.95,1341.15,9.51083,182.862,0,0,0),(105,1813.16,1333.64,10.5398,0,'None',500000,2,3,0,1817.8,1326.64,9.50139,89.123,0,0,0),(106,1800.52,1337.78,10.2236,0,'None',500000,2,3,0,1800.79,1325.65,9.63481,88.9572,0,0,0),(108,1763.85,1334.23,10.1264,0,'None',500000,2,3,0,1766.51,1326.61,9.50257,92.8979,0,0,0),(109,2038.97,1340.12,26.7362,0,'None',750000,2,3,0,2029.9,1325.46,26.0165,88.1995,0,0,0),(110,2060.38,1340.02,26.635,0,'None',750000,2,3,0,2055.56,1325.09,26.0348,89.2908,0,0,0),(111,1943.52,1752.95,15.357,0,'None',1000000,2,3,0,1959.88,1754.69,15.3082,179.534,0,0,0),(112,1995,1746.37,15.6921,0,'None',1000000,2,3,0,1969.7,1742.38,15.3268,2.47123,0,0,0),(113,1943.61,1806.85,15.7021,0,'None',1000000,2,3,0,1959.82,1799.99,15.3084,180.159,0,0,0),(114,1749.3,2076.2,16.575,0,'None',1500000,2,3,0,1765.97,2070.13,15.8205,179.242,0,0,0),(115,1745.79,2115.17,15.9475,0,'None',1500000,2,3,0,1765.79,2110.58,15.8212,181.535,0,0,0),(116,1747.09,2155.03,16.7052,0,'None',1500000,2,3,0,1765.9,2152.17,15.8188,179.311,0,0,0),(128,2379.72,-647.893,11.9928,0,'None',250000,1,3,0,2378.96,-639.972,11.7781,92.0288,0,0,0),(129,2379.74,-628.951,12.002,0,'None',250000,1,3,0,2378.3,-621.392,11.7782,92.1488,0,0,0),(130,2379.72,-609.882,12.002,0,'None',250000,1,3,0,2377.54,-601.698,11.7787,92.5009,0,0,0),(131,2379.72,-589.926,12.002,0,'None',250000,1,3,0,2378.36,-581.59,11.7787,92.3658,0,0,0),(132,2513.67,-230.501,2.56719,0,'None',250000,1,3,0,2508.92,-232.863,2.29269,358.318,0,0,0),(133,2487.49,-252.702,1.85739,0,'None',250000,1,3,0,2486.17,-248.168,1.76659,273.645,0,0,0),(134,2552.58,-967.056,2.01,0,'None',1500000,2,3,0,2565.22,-967.36,1.79029,180.396,0,0,0),(135,2134.76,-938.192,2.06813,0,'None',2500000,3,3,0,0,0,0,0,0,0,0),(136,1784.12,2838.43,12.5381,0,'None',250000,1,3,0,1794.11,2844.85,11.7956,180.675,0,0,0),(137,1783.89,2865.6,12.5381,0,'None',250000,1,3,0,1793.98,2870.17,11.7995,180.017,0,0,0),(138,1783.87,2891.98,12.5381,0,'None',250000,1,3,0,1794.36,2897.09,11.7986,178.9,0,0,0),(139,1762.61,2898,12.3931,0,'None',250000,1,3,0,1757.82,2907.17,11.8068,89.2469,0,0,0),(140,1749.46,2875.31,12.3931,0,'None',250000,1,3,0,1745.4,2875.53,11.8394,1.26452,0,0,0),(141,1752.2,2842.21,12.3931,0,'None',250000,1,3,0,1758.56,2831.96,11.816,89.2539,0,0,0),(142,1721.2,2842.25,12.3931,1,'None',250000,1,2,0,1722.85,2831.91,11.8088,271.755,0,0,0),(143,1718.56,2875.32,12.3931,0,'None',250000,1,3,0,1714.26,2865.53,11.8412,177.165,0,0,0),(144,1731.61,2897.93,12.3931,0,'None',250000,1,3,0,1729.12,2906.72,11.8015,269.574,0,0,0);
/*!40000 ALTER TABLE `houses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kvart`
--

DROP TABLE IF EXISTS `kvart`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kvart` (
  `kvart_id` int NOT NULL AUTO_INCREMENT,
  `kvart_days` int NOT NULL DEFAULT '3',
  `kvart_type` int NOT NULL DEFAULT '0',
  `kvart_pod_id` int NOT NULL DEFAULT '0',
  `kvart_Owned` int NOT NULL DEFAULT '0',
  `kvart_Owner` varchar(32) NOT NULL DEFAULT 'None',
  PRIMARY KEY (`kvart_id`)
) ENGINE=InnoDB AUTO_INCREMENT=825 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kvart`
--

LOCK TABLES `kvart` WRITE;
/*!40000 ALTER TABLE `kvart` DISABLE KEYS */;
INSERT INTO `kvart` VALUES (1,21,0,2,1,'None'),(2,25,1,2,1,'None'),(3,3,2,2,0,'None'),(4,3,3,2,0,'None'),(5,3,4,2,0,'None'),(6,3,5,2,0,'None'),(7,3,6,2,0,'None'),(8,3,7,2,0,'None'),(9,3,0,3,0,'None'),(10,3,1,3,0,'None'),(11,3,2,3,0,'None'),(12,3,3,3,0,'None'),(13,3,4,3,0,'None'),(14,3,5,3,0,'None'),(15,3,6,3,0,'None'),(16,3,7,3,0,'None'),(17,3,0,4,0,'None'),(18,3,1,4,0,'None'),(19,3,2,4,0,'None'),(20,3,3,4,0,'None'),(21,3,4,4,0,'None'),(22,3,5,4,0,'None'),(23,3,6,4,0,'None'),(24,3,7,4,0,'None'),(25,3,0,5,0,'None'),(26,3,1,5,0,'None'),(27,3,2,5,0,'None'),(28,3,3,5,0,'None'),(29,3,4,5,0,'None'),(30,3,5,5,0,'None'),(31,3,6,5,0,'None'),(32,3,7,5,0,'None'),(33,3,0,5,0,'None'),(34,3,1,5,0,'None'),(35,3,2,5,0,'None'),(36,3,3,5,0,'None'),(37,3,4,5,0,'None'),(38,3,5,5,0,'None'),(39,3,6,5,0,'None'),(40,3,7,5,0,'None'),(41,3,0,6,0,'None'),(42,3,1,6,0,'None'),(43,3,2,6,0,'None'),(44,3,3,6,0,'None'),(45,3,4,6,0,'None'),(46,3,5,6,0,'None'),(47,3,6,6,0,'None'),(48,3,7,6,0,'None'),(49,3,0,7,0,'None'),(50,3,1,7,0,'None'),(51,3,2,7,0,'None'),(52,3,3,7,0,'None'),(53,3,4,7,0,'None'),(54,3,5,7,0,'None'),(55,3,6,7,0,'None'),(56,3,7,7,0,'None'),(57,3,0,8,0,'None'),(58,3,1,8,0,'None'),(59,3,2,8,0,'None'),(60,3,3,8,0,'None'),(61,3,4,8,0,'None'),(62,3,5,8,0,'None'),(63,3,6,8,0,'None'),(64,3,7,8,0,'None'),(65,3,0,9,0,'None'),(66,3,1,9,0,'None'),(67,3,2,9,0,'None'),(68,3,3,9,0,'None'),(69,3,4,9,0,'None'),(70,3,5,9,0,'None'),(71,3,6,9,0,'None'),(72,3,7,9,0,'None'),(73,3,0,10,0,'None'),(74,3,1,10,0,'None'),(75,3,2,10,0,'None'),(76,3,3,10,0,'None'),(77,3,4,10,0,'None'),(78,3,5,10,0,'None'),(79,3,6,10,0,'None'),(80,3,7,10,0,'None'),(81,3,0,11,0,'None'),(82,3,1,11,0,'None'),(83,3,2,11,0,'None'),(84,3,3,11,0,'None'),(85,3,4,11,0,'None'),(86,3,5,11,0,'None'),(87,3,6,11,0,'None'),(88,3,7,11,0,'None'),(89,3,0,12,0,'None'),(90,3,1,12,0,'None'),(91,3,2,12,0,'None'),(92,3,3,12,0,'None'),(93,3,4,12,0,'None'),(94,3,5,12,0,'None'),(95,3,6,12,0,'None'),(96,3,7,12,0,'None'),(97,3,0,13,0,'None'),(98,3,1,13,0,'None'),(99,3,2,13,0,'None'),(100,3,3,13,0,'None'),(101,3,4,13,0,'None'),(102,3,5,13,0,'None'),(103,3,6,13,0,'None'),(104,3,7,13,0,'None'),(105,3,0,14,0,'None'),(106,3,1,14,0,'None'),(107,3,2,14,0,'None'),(108,3,3,14,0,'None'),(109,3,4,14,0,'None'),(110,3,5,14,0,'None'),(111,3,6,14,0,'None'),(112,3,7,14,0,'None'),(113,3,0,15,0,'None'),(114,3,1,15,0,'None'),(115,3,2,15,0,'None'),(116,3,3,15,0,'None'),(117,3,4,15,0,'None'),(118,3,5,15,0,'None'),(119,3,6,15,0,'None'),(120,3,7,15,0,'None'),(121,3,0,16,0,'None'),(122,3,1,16,0,'None'),(123,3,2,16,0,'None'),(124,3,3,16,0,'None'),(125,3,4,16,0,'None'),(126,3,5,16,0,'None'),(127,3,6,16,0,'None'),(128,3,7,16,0,'None'),(129,3,0,17,0,'None'),(130,3,1,17,0,'None'),(131,3,2,17,0,'None'),(132,3,3,17,0,'None'),(133,3,4,17,0,'None'),(134,3,5,17,0,'None'),(135,3,6,17,0,'None'),(136,3,7,17,0,'None'),(137,3,0,18,0,'None'),(138,3,1,18,0,'None'),(139,3,2,18,0,'None'),(140,3,3,18,0,'None'),(141,3,4,18,0,'None'),(142,3,5,18,0,'None'),(143,3,6,18,0,'None'),(144,3,7,18,0,'None'),(145,3,0,19,0,'None'),(146,3,1,19,0,'None'),(147,3,2,19,0,'None'),(148,3,3,19,0,'None'),(149,3,4,19,0,'None'),(150,3,5,19,0,'None'),(151,3,6,19,0,'None'),(152,3,7,19,0,'None'),(153,3,0,20,0,'None'),(154,3,1,20,0,'None'),(155,3,2,20,0,'None'),(156,3,3,20,0,'None'),(157,3,4,20,0,'None'),(158,3,5,20,0,'None'),(159,3,6,20,0,'None'),(160,3,7,20,0,'None'),(161,3,0,21,0,'None'),(162,3,1,21,0,'None'),(163,3,2,21,0,'None'),(164,3,3,21,0,'None'),(165,3,4,21,0,'None'),(166,3,5,21,0,'None'),(167,3,6,21,0,'None'),(168,3,7,21,0,'None'),(169,3,0,22,0,'None'),(170,3,1,22,0,'None'),(171,3,2,22,0,'None'),(172,3,3,22,0,'None'),(173,3,4,22,0,'None'),(174,3,5,22,0,'None'),(175,3,6,22,0,'None'),(176,3,7,22,0,'None'),(177,3,0,23,0,'None'),(178,3,1,23,0,'None'),(179,3,2,23,0,'None'),(180,3,3,23,0,'None'),(181,3,4,23,0,'None'),(182,3,5,23,0,'None'),(183,3,6,23,0,'None'),(184,3,7,23,0,'None'),(185,3,0,24,0,'None'),(186,3,1,24,0,'None'),(187,3,2,24,0,'None'),(188,3,3,24,0,'None'),(189,3,4,24,0,'None'),(190,3,5,24,0,'None'),(191,3,6,24,0,'None'),(192,3,7,24,0,'None'),(193,3,0,25,0,'None'),(194,3,1,25,0,'None'),(195,3,2,25,0,'None'),(196,3,3,25,0,'None'),(197,3,4,25,0,'None'),(198,3,5,25,0,'None'),(199,3,6,25,0,'None'),(200,3,7,25,0,'None'),(201,3,0,26,0,'None'),(202,3,1,26,0,'None'),(203,3,2,26,0,'None'),(204,3,3,26,0,'None'),(205,3,4,26,0,'None'),(206,3,5,26,0,'None'),(207,3,6,26,0,'None'),(208,3,7,26,0,'None'),(209,3,0,27,0,'None'),(210,3,1,27,0,'None'),(211,3,2,27,0,'None'),(212,3,3,27,0,'None'),(213,3,4,27,0,'None'),(214,3,5,27,0,'None'),(215,3,6,27,0,'None'),(216,3,7,27,0,'None'),(217,3,0,28,0,'None'),(218,3,1,28,0,'None'),(219,3,2,28,0,'None'),(220,3,3,28,0,'None'),(221,3,4,28,0,'None'),(222,3,5,28,0,'None'),(223,3,6,28,0,'None'),(224,3,7,28,0,'None'),(225,3,0,29,0,'None'),(226,3,1,29,0,'None'),(227,3,2,29,0,'None'),(228,3,3,29,0,'None'),(229,3,4,29,0,'None'),(230,3,5,29,0,'None'),(231,3,6,29,0,'None'),(232,3,7,29,0,'None'),(233,3,0,30,0,'None'),(234,3,1,30,0,'None'),(235,3,2,30,0,'None'),(236,3,3,30,0,'None'),(237,3,4,30,0,'None'),(238,3,5,30,0,'None'),(239,3,6,30,0,'None'),(240,3,7,30,0,'None'),(241,3,0,31,0,'None'),(242,3,1,31,0,'None'),(243,3,2,31,0,'None'),(244,3,3,31,0,'None'),(245,3,4,31,0,'None'),(246,3,5,31,0,'None'),(247,3,6,31,0,'None'),(248,3,7,31,0,'None'),(249,3,0,32,0,'None'),(250,3,1,32,0,'None'),(251,3,2,32,0,'None'),(252,3,3,32,0,'None'),(253,3,4,32,0,'None'),(254,3,5,32,0,'None'),(255,3,6,32,0,'None'),(256,3,7,32,0,'None'),(257,3,0,33,0,'None'),(258,3,1,33,0,'None'),(259,3,2,33,0,'None'),(260,3,3,33,0,'None'),(261,3,4,33,0,'None'),(262,3,5,33,0,'None'),(263,3,6,33,0,'None'),(264,3,7,33,0,'None'),(265,3,0,34,0,'None'),(266,3,1,34,0,'None'),(267,3,2,34,0,'None'),(268,3,3,34,0,'None'),(269,3,4,34,0,'None'),(270,3,5,34,0,'None'),(271,3,6,34,0,'None'),(272,3,7,34,0,'None'),(273,3,0,35,0,'None'),(274,3,1,35,0,'None'),(275,3,2,35,0,'None'),(276,3,3,35,0,'None'),(277,3,4,35,0,'None'),(278,3,5,35,0,'None'),(279,3,6,35,0,'None'),(280,3,7,35,0,'None'),(281,3,0,36,0,'None'),(282,3,1,36,0,'None'),(283,3,2,36,0,'None'),(284,3,3,36,0,'None'),(285,3,4,36,0,'None'),(286,3,5,36,0,'None'),(287,3,6,36,0,'None'),(288,3,7,36,0,'None'),(289,3,0,37,0,'None'),(290,3,1,37,0,'None'),(291,3,2,37,0,'None'),(292,3,3,37,0,'None'),(293,3,4,37,0,'None'),(294,3,5,37,0,'None'),(295,3,6,37,0,'None'),(296,3,7,37,0,'None'),(297,3,0,38,0,'None'),(298,3,1,38,0,'None'),(299,3,2,38,0,'None'),(300,3,3,38,0,'None'),(301,3,4,38,0,'None'),(302,3,5,38,0,'None'),(303,3,6,38,0,'None'),(304,3,7,38,0,'None'),(305,3,0,39,0,'None'),(306,3,1,39,0,'None'),(307,3,2,39,0,'None'),(308,3,3,39,0,'None'),(309,3,4,39,0,'None'),(310,3,5,39,0,'None'),(311,3,6,39,0,'None'),(312,3,7,39,0,'None'),(313,3,0,40,0,'None'),(314,3,1,40,0,'None'),(315,3,2,40,0,'None'),(316,3,3,40,0,'None'),(317,3,4,40,0,'None'),(318,3,5,40,0,'None'),(319,3,6,40,0,'None'),(320,3,7,40,0,'None'),(321,3,0,41,0,'None'),(322,3,1,41,0,'None'),(323,3,2,41,0,'None'),(324,3,3,41,0,'None'),(325,3,4,41,0,'None'),(326,3,5,41,0,'None'),(327,3,6,41,0,'None'),(328,3,7,41,0,'None'),(337,3,0,43,0,'None'),(338,3,1,43,0,'None'),(339,3,2,43,0,'None'),(340,3,3,43,0,'None'),(341,3,4,43,0,'None'),(342,3,5,43,0,'None'),(343,3,6,43,0,'None'),(344,3,7,43,0,'None'),(345,3,0,44,0,'None'),(346,3,1,44,0,'None'),(347,3,2,44,0,'None'),(348,3,3,44,0,'None'),(349,3,4,44,0,'None'),(350,3,5,44,0,'None'),(351,3,6,44,0,'None'),(352,3,7,44,0,'None'),(353,3,0,45,0,'None'),(354,3,1,45,0,'None'),(355,3,2,45,0,'None'),(356,3,3,45,0,'None'),(357,3,4,45,0,'None'),(358,3,5,45,0,'None'),(359,3,6,45,0,'None'),(360,3,7,45,0,'None'),(361,3,0,46,0,'None'),(362,3,1,46,0,'None'),(363,3,2,46,0,'None'),(364,3,3,46,0,'None'),(365,3,4,46,0,'None'),(366,3,5,46,0,'None'),(367,3,6,46,0,'None'),(368,3,7,46,0,'None'),(369,3,0,47,0,'None'),(370,3,1,47,0,'None'),(371,3,2,47,0,'None'),(372,3,3,47,0,'None'),(373,3,4,47,0,'None'),(374,3,5,47,0,'None'),(375,3,6,47,0,'None'),(376,3,7,47,0,'None'),(385,3,0,49,0,'None'),(386,3,1,49,0,'None'),(387,3,2,49,0,'None'),(388,3,3,49,0,'None'),(389,3,4,49,0,'None'),(390,3,5,49,0,'None'),(391,3,6,49,0,'None'),(392,3,7,49,0,'None'),(393,3,0,50,0,'None'),(394,3,1,50,0,'None'),(395,3,2,50,0,'None'),(396,3,3,50,0,'None'),(397,3,4,50,0,'None'),(398,3,5,50,0,'None'),(399,3,6,50,0,'None'),(400,3,7,50,0,'None'),(401,3,0,51,0,'None'),(402,3,1,51,0,'None'),(403,3,2,51,0,'None'),(404,3,3,51,0,'None'),(405,3,4,51,0,'None'),(406,3,5,51,0,'None'),(407,3,6,51,0,'None'),(408,3,7,51,0,'None'),(409,3,0,52,0,'None'),(410,3,1,52,0,'None'),(411,3,2,52,0,'None'),(412,3,3,52,0,'None'),(413,3,4,52,0,'None'),(414,3,5,52,0,'None'),(415,3,6,52,0,'None'),(416,3,7,52,0,'None'),(417,3,0,53,0,'None'),(418,3,1,53,0,'None'),(419,3,2,53,0,'None'),(420,3,3,53,0,'None'),(421,3,4,53,0,'None'),(422,3,5,53,0,'None'),(423,3,6,53,0,'None'),(424,3,7,53,0,'None'),(425,3,0,54,0,'None'),(426,3,1,54,0,'None'),(427,3,2,54,0,'None'),(428,3,3,54,0,'None'),(429,3,4,54,0,'None'),(430,3,5,54,0,'None'),(431,3,6,54,0,'None'),(432,3,7,54,0,'None'),(433,3,0,55,0,'None'),(434,3,1,55,0,'None'),(435,3,2,55,0,'None'),(436,3,3,55,0,'None'),(437,3,4,55,0,'None'),(438,3,5,55,0,'None'),(439,3,6,55,0,'None'),(440,3,7,55,0,'None'),(441,3,0,56,0,'None'),(442,3,1,56,0,'None'),(443,3,2,56,0,'None'),(444,3,3,56,0,'None'),(445,3,4,56,0,'None'),(446,3,5,56,0,'None'),(447,3,6,56,0,'None'),(448,3,7,56,0,'None'),(449,3,0,57,0,'None'),(450,3,1,57,0,'None'),(451,3,2,57,0,'None'),(452,3,3,57,0,'None'),(453,3,4,57,0,'None'),(454,3,5,57,0,'None'),(455,3,6,57,0,'None'),(456,3,7,57,0,'None'),(457,3,0,58,0,'None'),(458,3,1,58,0,'None'),(459,3,2,58,0,'None'),(460,3,3,58,0,'None'),(461,3,4,58,0,'None'),(462,3,5,58,0,'None'),(463,3,6,58,0,'None'),(464,3,7,58,0,'None'),(465,3,0,59,0,'None'),(466,3,1,59,0,'None'),(467,3,2,59,0,'None'),(468,3,3,59,0,'None'),(469,3,4,59,0,'None'),(470,3,5,59,0,'None'),(471,3,6,59,0,'None'),(472,3,7,59,0,'None'),(473,3,0,60,0,'None'),(474,3,1,60,0,'None'),(475,3,2,60,0,'None'),(476,3,3,60,0,'None'),(477,3,4,60,0,'None'),(478,3,5,60,0,'None'),(479,3,6,60,0,'None'),(480,3,7,60,0,'None'),(481,3,0,61,0,'None'),(482,3,1,61,0,'None'),(483,3,2,61,0,'None'),(484,3,3,61,0,'None'),(485,3,4,61,0,'None'),(486,3,5,61,0,'None'),(487,3,6,61,0,'None'),(488,3,7,61,0,'None'),(489,3,0,62,0,'None'),(490,3,1,62,0,'None'),(491,3,2,62,0,'None'),(492,3,3,62,0,'None'),(493,3,4,62,0,'None'),(494,3,5,62,0,'None'),(495,3,6,62,0,'None'),(496,3,7,62,0,'None'),(497,3,0,63,0,'None'),(498,3,1,63,0,'None'),(499,3,2,63,0,'None'),(500,3,3,63,0,'None'),(501,3,4,63,0,'None'),(502,3,5,63,0,'None'),(503,3,6,63,0,'None'),(504,3,7,63,0,'None'),(505,3,0,64,0,'None'),(506,3,1,64,0,'None'),(507,3,2,64,0,'None'),(508,3,3,64,0,'None'),(509,3,4,64,0,'None'),(510,3,5,64,0,'None'),(511,3,6,64,0,'None'),(512,3,7,64,0,'None'),(513,3,0,65,0,'None'),(514,3,1,65,0,'None'),(515,3,2,65,0,'None'),(516,3,3,65,0,'None'),(517,3,4,65,0,'None'),(518,3,5,65,0,'None'),(519,3,6,65,0,'None'),(520,3,7,65,0,'None'),(521,3,0,66,0,'None'),(522,3,1,66,0,'None'),(523,3,2,66,0,'None'),(524,3,3,66,0,'None'),(525,3,4,66,0,'None'),(526,3,5,66,0,'None'),(527,3,6,66,0,'None'),(528,3,7,66,0,'None'),(529,3,0,67,0,'None'),(530,3,1,67,0,'None'),(531,3,2,67,0,'None'),(532,3,3,67,0,'None'),(533,3,4,67,0,'None'),(534,3,5,67,0,'None'),(535,3,6,67,0,'None'),(536,3,7,67,0,'None'),(537,3,0,68,0,'None'),(538,3,1,68,0,'None'),(539,3,2,68,0,'None'),(540,3,3,68,0,'None'),(541,3,4,68,0,'None'),(542,3,5,68,0,'None'),(543,3,6,68,0,'None'),(544,3,7,68,0,'None'),(545,3,0,69,0,'None'),(546,3,1,69,0,'None'),(547,3,2,69,0,'None'),(548,3,3,69,0,'None'),(549,3,4,69,0,'None'),(550,3,5,69,0,'None'),(551,3,6,69,0,'None'),(552,3,7,69,0,'None'),(553,3,0,70,0,'None'),(554,3,1,70,0,'None'),(555,3,2,70,0,'None'),(556,3,3,70,0,'None'),(557,3,4,70,0,'None'),(558,3,5,70,0,'None'),(559,3,6,70,0,'None'),(560,3,7,70,0,'None'),(561,3,0,71,0,'None'),(562,3,1,71,0,'None'),(563,3,2,71,0,'None'),(564,3,3,71,0,'None'),(565,3,4,71,0,'None'),(566,3,5,71,0,'None'),(567,3,6,71,0,'None'),(568,3,7,71,0,'None'),(569,3,0,72,0,'None'),(570,3,1,72,0,'None'),(571,3,2,72,0,'None'),(572,3,3,72,0,'None'),(573,3,4,72,0,'None'),(574,3,5,72,0,'None'),(575,3,6,72,0,'None'),(576,3,7,72,0,'None'),(577,3,0,73,0,'None'),(578,3,1,73,0,'None'),(579,3,2,73,0,'None'),(580,3,3,73,0,'None'),(581,3,4,73,0,'None'),(582,3,5,73,0,'None'),(583,3,6,73,0,'None'),(584,3,7,73,0,'None'),(585,3,0,74,0,'None'),(586,3,1,74,0,'None'),(587,3,2,74,0,'None'),(588,3,3,74,0,'None'),(589,3,4,74,0,'None'),(590,3,5,74,0,'None'),(591,3,6,74,0,'None'),(592,3,7,74,0,'None'),(593,3,0,75,0,'None'),(594,3,1,75,0,'None'),(595,3,2,75,0,'None'),(596,3,3,75,0,'None'),(597,3,4,75,0,'None'),(598,3,5,75,0,'None'),(599,3,6,75,0,'None'),(600,3,7,75,0,'None'),(601,3,0,76,0,'None'),(602,3,1,76,0,'None'),(603,3,2,76,0,'None'),(604,3,3,76,0,'None'),(605,3,4,76,0,'None'),(606,3,5,76,0,'None'),(607,3,6,76,0,'None'),(608,3,7,76,0,'None'),(609,3,0,77,0,'None'),(610,3,1,77,0,'None'),(611,3,2,77,0,'None'),(612,3,3,77,0,'None'),(613,3,4,77,0,'None'),(614,3,5,77,0,'None'),(615,3,6,77,0,'None'),(616,3,7,77,0,'None'),(617,3,0,78,0,'None'),(618,3,1,78,0,'None'),(619,3,2,78,0,'None'),(620,3,3,78,0,'None'),(621,3,4,78,0,'None'),(622,3,5,78,0,'None'),(623,3,6,78,0,'None'),(624,3,7,78,0,'None'),(625,3,0,79,0,'None'),(626,3,1,79,0,'None'),(627,3,2,79,0,'None'),(628,3,3,79,0,'None'),(629,3,4,79,0,'None'),(630,3,5,79,0,'None'),(631,3,6,79,0,'None'),(632,3,7,79,0,'None'),(633,3,0,80,0,'None'),(634,3,1,80,0,'None'),(635,3,2,80,0,'None'),(636,3,3,80,0,'None'),(637,3,4,80,0,'None'),(638,3,5,80,0,'None'),(639,3,6,80,0,'None'),(640,3,7,80,0,'None'),(641,3,0,81,0,'None'),(642,3,1,81,0,'None'),(643,3,2,81,0,'None'),(644,3,3,81,0,'None'),(645,3,4,81,0,'None'),(646,3,5,81,0,'None'),(647,3,6,81,0,'None'),(648,3,7,81,0,'None'),(649,3,0,82,0,'None'),(650,3,1,82,0,'None'),(651,3,2,82,0,'None'),(652,3,3,82,0,'None'),(653,3,4,82,0,'None'),(654,3,5,82,0,'None'),(655,3,6,82,0,'None'),(656,3,7,82,0,'None'),(657,3,0,83,0,'None'),(658,3,1,83,0,'None'),(659,3,2,83,0,'None'),(660,3,3,83,0,'None'),(661,3,4,83,0,'None'),(662,3,5,83,0,'None'),(663,3,6,83,0,'None'),(664,3,7,83,0,'None'),(665,3,0,84,0,'None'),(666,3,1,84,0,'None'),(667,3,2,84,0,'None'),(668,3,3,84,0,'None'),(669,3,4,84,0,'None'),(670,3,5,84,0,'None'),(671,3,6,84,0,'None'),(672,3,7,84,0,'None'),(673,3,0,85,0,'None'),(674,3,1,85,0,'None'),(675,3,2,85,0,'None'),(676,3,3,85,0,'None'),(677,3,4,85,0,'None'),(678,3,5,85,0,'None'),(679,3,6,85,0,'None'),(680,3,7,85,0,'None'),(681,3,0,86,0,'None'),(682,3,1,86,0,'None'),(683,3,2,86,0,'None'),(684,3,3,86,0,'None'),(685,3,4,86,0,'None'),(686,3,5,86,0,'None'),(687,3,6,86,0,'None'),(688,3,7,86,0,'None'),(689,3,0,87,0,'None'),(690,3,1,87,0,'None'),(691,3,2,87,0,'None'),(692,3,3,87,0,'None'),(693,3,4,87,0,'None'),(694,3,5,87,0,'None'),(695,3,6,87,0,'None'),(696,3,7,87,0,'None'),(697,3,0,88,0,'None'),(698,3,1,88,0,'None'),(699,3,2,88,0,'None'),(700,3,3,88,0,'None'),(701,3,4,88,0,'None'),(702,3,5,88,0,'None'),(703,3,6,88,0,'None'),(704,3,7,88,0,'None'),(705,3,0,89,0,'None'),(706,3,1,89,0,'None'),(707,3,2,89,0,'None'),(708,3,3,89,0,'None'),(709,3,4,89,0,'None'),(710,3,5,89,0,'None'),(711,3,6,89,0,'None'),(712,3,7,89,0,'None'),(713,3,0,90,0,'None'),(714,3,1,90,0,'None'),(715,3,2,90,0,'None'),(716,3,3,90,0,'None'),(717,3,4,90,0,'None'),(718,3,5,90,0,'None'),(719,3,6,90,0,'None'),(720,3,7,90,0,'None'),(721,3,0,91,0,'None'),(722,3,1,91,0,'None'),(723,3,2,91,0,'None'),(724,3,3,91,0,'None'),(725,3,4,91,0,'None'),(726,3,5,91,0,'None'),(727,3,6,91,0,'None'),(728,3,7,91,0,'None'),(729,3,0,92,0,'None'),(730,3,1,92,0,'None'),(731,3,2,92,0,'None'),(732,3,3,92,0,'None'),(733,3,4,92,0,'None'),(734,3,5,92,0,'None'),(735,3,6,92,0,'None'),(736,3,7,92,0,'None'),(737,3,0,93,0,'None'),(738,3,1,93,0,'None'),(739,3,2,93,0,'None'),(740,3,3,93,0,'None'),(741,3,4,93,0,'None'),(742,3,5,93,0,'None'),(743,3,6,93,0,'None'),(744,3,7,93,0,'None'),(745,3,0,94,0,'None'),(746,3,1,94,0,'None'),(747,3,2,94,0,'None'),(748,3,3,94,0,'None'),(749,3,4,94,0,'None'),(750,3,5,94,0,'None'),(751,3,6,94,0,'None'),(752,3,7,94,0,'None'),(753,3,0,95,0,'None'),(754,3,1,95,0,'None'),(755,3,2,95,0,'None'),(756,3,3,95,0,'None'),(757,3,4,95,0,'None'),(758,3,5,95,0,'None'),(759,3,6,95,0,'None'),(760,3,7,95,0,'None'),(761,3,0,96,0,'None'),(762,3,1,96,0,'None'),(763,3,2,96,0,'None'),(764,3,3,96,0,'None'),(765,3,4,96,0,'None'),(766,3,5,96,0,'None'),(767,3,6,96,0,'None'),(768,3,7,96,0,'None'),(769,3,0,97,0,'None'),(770,3,1,97,0,'None'),(771,3,2,97,0,'None'),(772,3,3,97,0,'None'),(773,3,4,97,0,'None'),(774,3,5,97,0,'None'),(775,3,6,97,0,'None'),(776,3,7,97,0,'None'),(777,3,0,98,0,'None'),(778,3,1,98,0,'None'),(779,3,2,98,0,'None'),(780,3,3,98,0,'None'),(781,3,4,98,0,'None'),(782,3,5,98,0,'None'),(783,3,6,98,0,'None'),(784,3,7,98,0,'None'),(785,3,0,99,0,'None'),(786,3,1,99,0,'None'),(787,3,2,99,0,'None'),(788,3,3,99,0,'None'),(789,3,4,99,0,'None'),(790,3,5,99,0,'None'),(791,3,6,99,0,'None'),(792,3,7,99,0,'None'),(793,3,0,100,0,'None'),(794,3,1,100,0,'None'),(795,3,2,100,0,'None'),(796,3,3,100,0,'None'),(797,3,4,100,0,'None'),(798,3,5,100,0,'None'),(799,3,6,100,0,'None'),(800,3,7,100,0,'None'),(801,3,0,101,0,'None'),(802,3,1,101,0,'None'),(803,3,2,101,0,'None'),(804,3,3,101,0,'None'),(805,3,4,101,0,'None'),(806,3,5,101,0,'None'),(807,3,6,101,0,'None'),(808,3,7,101,0,'None'),(809,3,0,102,0,'None'),(810,3,1,102,0,'None'),(811,3,2,102,0,'None'),(812,3,3,102,0,'None'),(813,3,4,102,0,'None'),(814,3,5,102,0,'None'),(815,3,6,102,0,'None'),(816,3,7,102,0,'None'),(817,3,0,103,0,'None'),(818,3,1,103,0,'None'),(819,3,2,103,0,'None'),(820,3,3,103,0,'None'),(821,3,4,103,0,'None'),(822,3,5,103,0,'None'),(823,3,6,103,0,'None'),(824,3,7,103,0,'None');
/*!40000 ALTER TABLE `kvart` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nakazania`
--

DROP TABLE IF EXISTS `nakazania`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `nakazania` (
  `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `AdminName` varchar(24) NOT NULL,
  `Name` varchar(24) NOT NULL,
  `AdminId` int NOT NULL,
  `AccountId` int NOT NULL,
  `Date` varchar(24) NOT NULL,
  `Time` int NOT NULL,
  `Reason` varchar(256) NOT NULL,
  `Type` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nakazania`
--

--
-- Table structure for table `name_log`
--

DROP TABLE IF EXISTS `name_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `name_log` (
  `nID` int NOT NULL AUTO_INCREMENT,
  `nAccountId` int NOT NULL,
  `nOldName` varchar(26) NOT NULL,
  `nNewName` varchar(26) NOT NULL,
  `nDate` date NOT NULL,
  PRIMARY KEY (`nID`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `name_log`
--

--
-- Table structure for table `org_history`
--

DROP TABLE IF EXISTS `org_history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `org_history` (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `date` bigint NOT NULL DEFAULT '0',
  `account_id` int NOT NULL DEFAULT '0',
  `org_id` smallint NOT NULL DEFAULT '0',
  `action_type` int NOT NULL DEFAULT '0',
  `data` varchar(144) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=138 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `org_history`
--

--
-- Table structure for table `other`
--

DROP TABLE IF EXISTS `other`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `other` (
  `miner_zp` int NOT NULL,
  `loader_zp` int NOT NULL,
  `diver_zp` int NOT NULL,
  `XDay` int NOT NULL,
  `SpeedHack_AC` int NOT NULL,
  `server_pass_status` int NOT NULL,
  `server_pass` varchar(24) NOT NULL DEFAULT 'None',
  `dm` int NOT NULL DEFAULT '1',
  `db` int NOT NULL DEFAULT '1',
  `mg` int NOT NULL DEFAULT '1',
  `epp` int NOT NULL DEFAULT '1',
  `nonrp` int NOT NULL DEFAULT '1',
  `drive` int NOT NULL DEFAULT '1',
  `caps` int NOT NULL DEFAULT '1',
  `flood` int NOT NULL DEFAULT '1',
  `offtop` int NOT NULL DEFAULT '1',
  `smiMoney` int NOT NULL DEFAULT '0',
  `next_contraband_time` int NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `other`
--

LOCK TABLES `other` WRITE;
/*!40000 ALTER TABLE `other` DISABLE KEYS */;
INSERT INTO `other` VALUES (4,50,100,1,0,0,'None',10,10,10,10,10,10,10,15,10,760,1641753893);
/*!40000 ALTER TABLE `other` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ownable_cars`
--

DROP TABLE IF EXISTS `ownable_cars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ownable_cars` (
  `id` int NOT NULL AUTO_INCREMENT,
  `owner_id` int NOT NULL DEFAULT '0',
  `model_id` int NOT NULL DEFAULT '400',
  `color` varchar(10) NOT NULL DEFAULT '0, 0',
  `number` varchar(32) NOT NULL DEFAULT 'None',
  `mileage` float NOT NULL DEFAULT '0',
  `lock` int NOT NULL DEFAULT '0',
  `fuel` float NOT NULL DEFAULT '80',
  `health` float NOT NULL DEFAULT '1000',
  `weels` int NOT NULL DEFAULT '0',
  `nitro` int NOT NULL DEFAULT '0',
  `cost_car` int NOT NULL DEFAULT '100',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=161 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ownable_cars`
--

--
-- Table structure for table `podezd`
--

DROP TABLE IF EXISTS `podezd`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `podezd` (
  `pod_id` int NOT NULL AUTO_INCREMENT,
  `pod_x` float NOT NULL DEFAULT '0',
  `pod_y` float NOT NULL DEFAULT '0',
  `pod_z` float NOT NULL DEFAULT '0',
  `a_car_pos_x` float NOT NULL DEFAULT '0',
  `a_car_pos_y` float NOT NULL DEFAULT '0',
  `a_car_pos_z` float NOT NULL DEFAULT '0',
  `a_car_pos_a` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`pod_id`)
) ENGINE=InnoDB AUTO_INCREMENT=104 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `podezd`
--

LOCK TABLES `podezd` WRITE;
/*!40000 ALTER TABLE `podezd` DISABLE KEYS */;
INSERT INTO `podezd` VALUES (2,2128.25,1860.09,12.1697,2124.17,1854.71,12.2165,89.7724),(3,2128.25,1841.51,12.1697,2124.08,1836.35,12.2121,89.5963),(4,2128.25,1822.9,12.1697,2124.11,1819.06,11.8662,90.2771),(5,1751.54,2419.84,15.3593,1756.88,2418.21,15.1358,214.258),(6,1748.59,2409.31,15.3593,1753.88,2408.65,15.1359,303.341),(7,1758.03,2394.92,15.3501,1763.82,2395.37,15.0973,304.272),(8,1767.16,2381.44,15.299,1774.09,2380.18,15.0438,303.947),(9,1793.38,2400.6,15.3096,1790.16,2393.92,15.0505,125.179),(10,1787.68,2409.32,15.3177,1785.44,2403.25,15.0471,125.831),(11,1806.49,2372.31,15.3593,1793.69,2359.47,15.1357,213.666),(12,1825.51,2343.83,15.3514,1817.26,2338.03,15.1358,303.266),(13,1834.29,2330.36,15.3553,1826.11,2325.01,15.128,301.74),(14,1840.33,2302.29,15.2572,1836.38,2306.28,15.0901,117.167),(15,1845.23,2294.07,15.2572,1843.73,2298.85,15.038,207.56),(16,1847.36,2290.31,15.2572,1850.79,2287.17,15.0651,34.8544),(17,1857.77,2297.62,15.2572,1858.48,2292.05,15.0214,29.5882),(18,1852.68,2305.81,15.2572,1853.19,2300.64,15.0339,32.4901),(19,1850.5,2309.49,15.2572,1849.7,2314.19,15.1054,118.879),(20,1859.76,2198.57,15.9369,1843.36,2195.32,15.4362,181.335),(21,1859.48,2164.48,15.9369,1855.05,2169.29,15.6706,358.512),(22,1859.68,2148.44,15.9983,1854.68,2153.83,15.7131,358.637),(23,1814.33,2165.3,15.5891,1808.74,2159.29,15.38,1.87961),(24,1814.38,2181.77,15.5886,1809.17,2174.64,15.3977,0.342204),(25,1790.17,2179.4,16.0557,1794.7,2173.8,15.7186,0.750369),(26,1790.43,2163.29,15.9916,1794.92,2157.81,15.7129,0.78484),(27,2560.44,-1794.94,22.0497,2565.32,-1791.34,21.6967,268.612),(28,2560.45,-1813.49,22.0497,2565.18,-1809.9,21.6963,270.109),(29,2560.45,-1831.96,22.0497,2565.19,-1828.09,21.6966,272.258),(30,2560.45,-1850.59,22.0497,2565.73,-1847.31,21.6961,270.899),(31,2416.84,-1913.97,22.0043,2435.9,-1906.58,21.7806,90.3612),(32,2416.75,-1926.12,22.0043,2436.78,-1912.81,21.7807,93.0404),(33,2416.73,-1938.08,22.0043,2441.5,-1942.18,21.7807,2.75286),(34,2426.81,-1945.62,22.0043,2437.1,-1942.33,21.78,2.40759),(35,2414.96,-1966.91,22.0043,0,0,0,0),(36,2401.25,-2027.64,22.101,2409.87,-2027.27,21.6461,1.1898),(37,2401.04,-2046.23,22.101,2410.1,-2045.87,21.6473,1.04333),(38,2401.25,-2064.81,22.101,2409.67,-2064.61,21.6465,1.03249),(39,2401.22,-2083.29,22.101,2409.95,-2083.81,21.6447,0.60381),(40,2443.09,-2115.74,22.1197,2436.83,-2100.66,21.5586,89.5474),(41,2436.45,-2131.89,22.1197,2436.32,-2106.88,21.5587,90.0911),(43,2407.95,-2131.7,22.1197,2435.94,-2113.01,21.5588,91.5727),(44,2335.92,-2083.15,22.101,2344.68,-2083.27,21.6462,3.49786),(45,2335.93,-2064.68,22.101,2344.8,-2064.61,21.6467,0.94223),(46,2335.97,-2046.12,22.101,2344.61,-2046.03,21.6471,0.869102),(47,2335.97,-2027.63,22.101,2344.5,-2027.17,21.6463,0.527253),(49,2148.08,-2309.31,21.95,2152.65,-2315.05,21.7266,183.312),(50,2162.56,-2309.32,21.95,2167.61,-2315.03,21.7265,182.834),(51,2177.62,-2309.32,21.95,2181.31,-2314.59,21.7267,182.365),(52,2096.92,-2364.34,22.4377,2102.28,-2368.11,21.7263,180.209),(53,2111.78,-2364.35,22.4377,2116.62,-2368.44,21.7266,179.839),(54,2126.89,-2364.34,22.4377,2131.9,-2368.87,21.7266,181.248),(55,2155.42,-2392.05,22.0402,2155.7,-2384.92,21.6117,269.802),(56,2142.21,-2364.34,22.4377,2148.25,-2368.84,21.7262,179.816),(57,2168.37,-2362.07,22.4377,2163.44,-2366.56,21.7264,180.649),(58,2178.64,-2392.24,22.0557,2178.11,-2385.23,21.6161,268.343),(59,2183.32,-2362.07,22.4377,2179.65,-2365.62,21.7268,180.301),(60,2211.15,-2392.24,22.0557,2210.46,-2385.04,21.6136,270.648),(61,2198.54,-2362.08,22.4377,2193.6,-2365.71,21.7267,179.674),(62,2234.04,-2392.14,22.0478,2231.58,-2383.98,21.6112,295.535),(63,2213.53,-2362.07,22.4377,2209.62,-2365.54,21.7362,180.846),(64,2640.68,-2411.81,22.5529,2651.48,-2412.32,21.6443,358.23),(65,2640.4,-2396,22.5452,2651.53,-2395.79,21.6431,0.697415),(66,2640.4,-2380.06,22.5452,2650.99,-2379.75,21.6413,1.70998),(67,2640.34,-2214.21,22.5529,2651.63,-2214.55,21.6456,359.089),(68,2640.4,-2364,22.5529,2651.07,-2363.71,21.6465,357.484),(69,2640.33,-2230.15,22.5452,2651.56,-2230.82,21.6447,0.314242),(70,2640.4,-2337.21,22.5452,2651.69,-2337.3,21.6472,359.357),(71,2640.41,-2321.1,22.5452,2651.53,-2321.4,21.6409,4.1458),(72,2640.31,-2245.94,22.5452,2651.3,-2245.66,21.6442,2.9082),(73,2640.18,-2262.03,22.5452,2651.7,-2263.33,21.6452,0.935017),(74,2640.17,-2289.22,22.5529,2651.69,-2289.96,21.6468,1.1275),(75,2640.4,-2305.25,22.5452,2651.59,-2305.28,21.6429,2.37504),(76,1740.29,-2324.87,11.4047,1726.45,-2335.91,10.5821,269.238),(77,1740.3,-2348.75,11.4047,1726.55,-2349.43,10.5822,270.574),(78,1740.29,-2372.68,11.4047,1726.12,-2373.29,10.582,268.679),(79,1780.13,-2416.07,11.4047,1766.24,-2424.38,10.5823,270.219),(80,1780.22,-2440.13,11.4047,1766.33,-2441.25,10.582,268.307),(81,1780.17,-2464.27,11.4047,1766.63,-2465.13,10.5823,269.449),(82,1819.69,-2508.41,11.4047,1815.27,-2516.76,10.6739,0.322953),(83,1819.69,-2532.01,11.4047,1815.78,-2537.57,10.6738,1.64577),(84,1819.68,-2556.43,11.4047,1815.64,-2563.48,10.6741,0.018819),(85,2128.25,1804.37,12.1697,2123.48,1799.75,11.8661,91.0701),(86,2128.18,1779.39,12.1697,2124.39,1774.62,11.8663,92.045),(87,2128.18,1760.82,12.1697,2122.83,1756.7,11.8666,89.1389),(88,2128.18,1742.25,12.1697,2122.84,1737.41,11.8665,91.6907),(89,2128.18,1723.63,12.1697,2122.6,1718.84,11.8666,90.9108),(90,2127.24,1708.71,12.2034,2121.08,1713.22,11.8667,89.1908),(91,2127.24,1690.72,12.2034,2123.37,1687.61,11.8661,92.849),(92,2127.24,1669.96,12.2034,2122.01,1673.41,11.8765,89.2723),(93,2096.96,1669.86,12.2034,2101.47,1674.18,11.8756,269.728),(94,2096.96,1687.7,12.2034,2101.92,1691.43,11.8666,270.556),(95,2096.95,1708.4,12.2034,2102.81,1712.82,11.8666,269.494),(96,2095.99,1723.5,12.1697,2100.93,1718.65,11.8663,269.63),(97,2095.99,1742.07,12.1697,2101.87,1736.58,11.8666,269.619),(98,2095.99,1760.65,12.1697,2101.38,1755.32,11.8663,268.898),(99,2095.99,1779.22,12.1697,2101.34,1773.73,11.8662,269.644),(100,2095.91,1804.15,12.1697,2101.78,1798.66,11.8667,268.307),(101,2095.9,1822.78,12.1697,2101.54,1817.47,11.8665,268.778),(102,2095.9,1841.31,12.1697,2101.03,1836.03,11.8667,267.99),(103,2095.9,1859.97,12.1697,2100.71,1854.61,11.8662,270.256);
/*!40000 ALTER TABLE `podezd` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `radars`
--

DROP TABLE IF EXISTS `radars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `radars` (
  `radar_id` int NOT NULL AUTO_INCREMENT,
  `radar_set` varchar(32) NOT NULL DEFAULT 'Unigva RolePlay',
  `radar_type` int NOT NULL DEFAULT '1',
  `radar_speed` int NOT NULL DEFAULT '60',
  `radar_x` float NOT NULL,
  `radar_y` float NOT NULL,
  `radar_z` float NOT NULL,
  `radar_a` float NOT NULL,
  PRIMARY KEY (`radar_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `radars`
--

LOCK TABLES `radars` WRITE;
/*!40000 ALTER TABLE `radars` DISABLE KEYS */;
INSERT INTO `radars` VALUES (2,'Eduard_Dobbikov',2,60,1972.67,1898.3,14.49,-176.7),(3,'Eduard_Dobbikov',2,60,2757.23,-1382.47,22.3077,177.8),(4,'Eduard_Dobbikov',2,60,2736.75,-1383.26,22.1959,0),(6,'Kudasai_Volkov',1,20,1553.69,2959.95,10.88,0),(7,'Kudasai_Volkov',1,20,1524.51,2959.98,10.92,0);
/*!40000 ALTER TABLE `radars` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `referals`
--

DROP TABLE IF EXISTS `referals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `referals` (
  `login` varchar(24) NOT NULL,
  `login_invited` varchar(24) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `referals`
--

--
-- Table structure for table `repositories`
--

DROP TABLE IF EXISTS `repositories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `repositories` (
  `army_met` int NOT NULL DEFAULT '0',
  `army_patr` int NOT NULL DEFAULT '0',
  `OPG_O_METALL` int NOT NULL DEFAULT '0',
  `OPG_O_PATRON` int NOT NULL DEFAULT '0',
  `OPG_O_DRUGS` int NOT NULL DEFAULT '0',
  `OPG_O_STATUS` int NOT NULL DEFAULT '0',
  `OPG_S_METALL` int NOT NULL DEFAULT '0',
  `OPG_S_PATRON` int NOT NULL DEFAULT '0',
  `OPG_S_DRUGS` int NOT NULL DEFAULT '0',
  `OPG_S_STATUS` int NOT NULL DEFAULT '0',
  `OPG_O_MONEY` int NOT NULL DEFAULT '0',
  `OPG_S_MONEY` int NOT NULL DEFAULT '0',
  `ALL_NARKO` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `repositories`
--

LOCK TABLES `repositories` WRITE;
/*!40000 ALTER TABLE `repositories` DISABLE KEYS */;
INSERT INTO `repositories` VALUES (5015,9591,5000,5000,5500,0,5000,5000,5000,1,120000,18526,0);
/*!40000 ALTER TABLE `repositories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toilets`
--

DROP TABLE IF EXISTS `toilets`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `toilets` (
  `tID` int NOT NULL AUTO_INCREMENT,
  `tEnterX` float NOT NULL,
  `tEnterY` float NOT NULL,
  `tEnterZ` float NOT NULL,
  PRIMARY KEY (`tID`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toilets`
--

LOCK TABLES `toilets` WRITE;
/*!40000 ALTER TABLE `toilets` DISABLE KEYS */;
INSERT INTO `toilets` VALUES (1,1840.18,2511.91,15.6639),(2,1840.95,2510.7,15.6639),(3,1841.72,2509.56,15.6639),(4,1899.24,1701.68,15.8325),(5,1899.24,1703.14,15.8325),(6,1779.56,2245.96,15.7828),(7,1778.03,2245.95,15.8113),(8,1776.54,2245.95,15.8389),(9,2013.45,1953.54,15.51),(10,2015.04,1953.54,15.51),(11,2016.62,1953.54,15.51),(12,2339.42,2024.9,15.99),(13,2340.89,2025.15,15.99),(14,2342.24,2025.38,15.99),(15,2812.04,-1386.53,2.91506),(16,2086.75,1796.31,12.09),(17,2086.76,1794.94,12.09);
/*!40000 ALTER TABLE `toilets` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unwarn`
--

DROP TABLE IF EXISTS `unwarn`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `unwarn` (
  `UnWarnDate` int NOT NULL,
  `Nick` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `unwarn`
--

DROP TABLE IF EXISTS `deactivated_accs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `deactivated_accs` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `account_id` int NOT NULL DEFAULT '0',
    `date` int NOT NULL DEFAULT '0',
    `reason` varchar(256) NOT NULL,
    `admin_id` int NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `deactivated_accs`
--

DROP TABLE IF EXISTS `apvote`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `apvote` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `is_open` int NOT NULL DEFAULT '0',
    `lvl_access` int NOT NULL DEFAULT '0',

  `pos_x` float NOT NULL DEFAULT '0.0',
  `pos_y` float NOT NULL DEFAULT '0.0',
  `pos_z` float NOT NULL DEFAULT '0.0',

    `vote_name` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
--
--

DROP TABLE IF EXISTS `apvotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `apvotes` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `vote_id` int NOT NULL DEFAULT '0',
    `vote_var_id` int NOT NULL DEFAULT '0',
    `account_id` int NOT NULL DEFAULT '0',
    `date` int NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
--
--

DROP TABLE IF EXISTS `apvotevars`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `apvotevars` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `vote_id` int NOT NULL DEFAULT '0',
    `var_name` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
--
--

DROP TABLE IF EXISTS `connects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `connects` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `date` varchar(256) NOT NULL,
    `account_id` int NOT NULL DEFAULT '-1',
    `unixdate` int NOT NULL DEFAULT '0',
    `ip` varchar(256) NOT NULL,
    `nick` varchar(256) NOT NULL,
    `type` int NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
--
--



/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-01-08 15:59:29
