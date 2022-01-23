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