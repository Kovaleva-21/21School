<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'ccorliss' );

/** MySQL database password */
define( 'DB_PASSWORD', 'qwerty' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 * 
 */
    define('AUTH_KEY',         'p.qf &|GqqVkaT+:TPjkeHqLhE{4zN2|pb-!5Q6>;><e;>(p6K`$D+$~]E/-+ 1.');
    define('SECURE_AUTH_KEY',  '_ERFb}6s:t(Ly,=+.H6n7vuBTQ2%|P3.epn,|Ne{;|J9~MM*OacD^:w+~.4e!~T%');
    define('LOGGED_IN_KEY',    'Rf0r+7i,^3-Ci5vnuuMu5*5q_cO8qKiYnkFEQ*4j|*|[*}~CB$a.o9o1qx !(XP+');
    define('NONCE_KEY',        '/P4[!l9K6cm$X@QfS=iM?HRwz=!b-|@D Lcp<:-;&/jc~UXj:>~;4gdd0r#:$658');
    define('AUTH_SALT',        ',tjwcn<<WC^dTi?(#`+m+s(a-ov;++MKm]f]q_16<>.GkKq<g2drV}o,5Bt{DV8x');
    define('SECURE_AUTH_SALT', '{7rAz{N|&#E^pZ)hxpNovCzZ}`>ip[wa/ck1dG<]K7#z8Z:O&iP~_s1{]#+WM94A');
    define('LOGGED_IN_SALT',   'uTI2G7Z{?8is`!U@uAt)rK*2:-?Ieyv,W*,B`bS/#UJ6+pbhi!WGAW2zvW1!D|t8');
    define('NONCE_SALT',       '+v|L.3I +7vtO@~h}+;Fi}ocRKG+XI]wJnL)u@#6R@nr7Xq(+w11K:$14OD?uGF}');

    $table_prefix = 'wp_';

    define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
?>
