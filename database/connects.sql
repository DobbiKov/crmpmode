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