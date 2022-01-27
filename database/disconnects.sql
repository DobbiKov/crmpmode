DROP TABLE IF EXISTS `disconnects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `disconnects` (
    `dconn_id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `dconn_date` varchar(256) NOT NULL,
    `dconn_account_id` int NOT NULL DEFAULT '-1',
    `dconn_unixdate` int NOT NULL DEFAULT '0',
    `dconn_ip` varchar(256) NOT NULL,
    `dconn_nick` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;