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